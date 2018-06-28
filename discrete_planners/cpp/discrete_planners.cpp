#include "discrete_planners.h"

vector<Location> Random_planner::search(vector< vector<int> > world_state, Location robot_pose, Location goal_pose) {
  int rows = world_state.size();
  int cols = world_state[0].size();

  if(rows == 0 || cols == 0) {
    cout << "Error, empty world_state!!!" << endl;
    return {};
  }

  if(!is_pos_valid(robot_pose, rows, cols)) {
    cout << "Error, invalid robot_pose!!!" << endl;
    return {};
  }

  if(!is_pos_valid(goal_pose, rows, cols)) {
    cout << "Error, invalid goal_pose!!!" << endl;
    return {};
  }

  Location current(robot_pose.x, robot_pose.y);
  list<Location> recent_visited;
  vector< vector<int> > directions{
                        {-1, 0},
                        {1, 0},
                        {0, -1},
                        {0, 1} };
  vector<Location> path;
  bool found = false;
  int steps = 0;
  int steps_boundary = (int) sqrt(max_step_number);
  srand(time(NULL));

  while(steps < max_step_number) {
    path.push_back(current);

    // update recent_visited vector
    if(recent_visited.size() == steps_boundary) {
      recent_visited.pop_front();
    }
    recent_visited.push_back(current);

    if(current == goal_pose) {
      found = true;
      break;
    }

    vector<Location> available_positions;
    vector<Location> not_visited; // available positions that are not visited
                                  // in the last sqrt(max_step_number) steps.
    // find available next positions
    for(int i = 0; i < directions.size(); ++i) {
      int x = current.x + directions[i][0];
      int y = current.y + directions[i][1];
      Location pos(x, y);
      // check whether x and y are valid
      if(!is_pos_valid(pos, rows, cols)) {
        continue;
      }

      if(world_state[x][y] == 0) {
        available_positions.push_back(pos);
        if(find(recent_visited.begin(), recent_visited.end(), pos) == recent_visited.end()) {
          not_visited.push_back(pos);
        }
      }
    }

    // randomly pick one position that was not visited in the last
    // sqrt(max_step_number) steps except if this is the only available option
    if(available_positions.size() < 1) {
      break;
    }
    else if (available_positions.size() == 1){
      current = available_positions[0];
    }
    else {
      int idx;
      // if all available positions are not visited or all of them are visited
      if(not_visited.size() == available_positions.size() or not_visited.size() == 0) {
        idx = rand() % available_positions.size();
        current = available_positions[idx];
      }
      else {
        idx = rand() % not_visited.size();
        current = not_visited[idx];
      }
    }

    steps += 1;
  }

  if(found) return path;
  else return {};
}


vector<Location> Optimal_planner::search(vector< vector<int> > world_state, Location robot_pose, Location goal_pose) {
  int rows = world_state.size();
  int cols = world_state[0].size();

  if(rows == 0 || cols == 0) {
    cout << "Error, empty world_state!!!" << endl;
    return {};
  }

  if(!is_pos_valid(robot_pose, rows, cols)) {
    cout << "Error, invalid robot_pose!!!" << endl;
    return {};
  }

  if(!is_pos_valid(goal_pose, rows, cols)) {
    cout << "Error, invalid goal_pose!!!" << endl;
    return {};
  }

  vector< vector<int> > directions{
                        {-1, 0},
                        {1, 0},
                        {0, -1},
                        {0, 1} };
  bool found = false;

  int g = 0, h = heuristic(robot_pose, goal_pose);
  int x = robot_pose.x, y = robot_pose.y;
  vector<vector<int> > open;
  open.push_back({g+h, x, y});

  int x2, y2;
  map<Location, Location> came_from;
  map<Location, int> cost_so_far;
  Location dummy(-1, -1);
  came_from[robot_pose] = dummy;
  cost_so_far[robot_pose] = 0;

  while(open.size()) {
    sort(open.begin(), open.end());
    reverse(open.begin(), open.end());

    vector<int> next;

    // Stored the poped value into next
    next = open.back();
    open.pop_back();

    x = next[1];
    y = next[2];
    Location pos(x, y);
    int g = cost_so_far[pos];

    if(pos == goal_pose) {
      found = true;
      break;
    }
    else {
      // find available next positions
      for(int i = 0; i < directions.size(); ++i) {
        x2 = x + directions[i][0];
        y2 = y + directions[i][1];
        Location pos2(x2, y2);

        // check whether x2 and y2 are valid
        if(!is_pos_valid(pos2, rows, cols)) {
          continue;
        }

        int g2 = g + 1;
        // if not visited, store the cost_so_far, otherwise update if lower cost exists
        if(world_state[x2][y2] == 0 &&
          (cost_so_far.find(pos2) == cost_so_far.end() || g2 < cost_so_far[pos2])) {
          int h2 = heuristic(pos2, goal_pose);
          open.push_back({g2+h2, x2, y2});
          cost_so_far[pos2] = g2;
          came_from[pos2] = pos;
        }

      }
    }

  }

  vector<Location> path;
  if(found) {
    path.push_back(goal_pose);
    Location current(goal_pose.x, goal_pose.y);
    while(!(came_from[current] == dummy)) {
      current = came_from[current];
      path.push_back(current);
    }
    reverse(path.begin(), path.end());
    return path;
  }
  return {};
}

#include "discrete_planners.h"
void print_locations(vector<Location> path) {
  for(int i = 0; i < path.size(); ++i) {
    if(i == 0) cout << "[" ;
    cout << "(" << path[i].x << ", "<< path[i].y << ")";
    if(i < path.size() - 1) cout << ", ";
    else cout << "]\n";
  }
}


void test(const vector< vector<int> >& world_state, Location& robot_pose, Location&
      goal_pose, Random_planner& random_planner, Optimal_planner& optimal_planner) {
        vector<Location> path;
        cout << "Random_planner:" << endl;
        path = random_planner.search(world_state, robot_pose, goal_pose);
        print_locations(path);
        cout << "Optimal_planner:" << endl;
        path = optimal_planner.search(world_state, robot_pose, goal_pose);
        print_locations(path);
      }

int main() {
  Random_planner random_planner;
  Optimal_planner optimal_planner;
  vector<Location> path;
  // empty world_state
  vector< vector<int> > world_state = {{}};
  Location robot_pose(2, 0), goal_pose(5, 5);

  cout << "\nTest empty world_state:" << endl;
  test(world_state, robot_pose, goal_pose, random_planner, optimal_planner);

  // invalid robot_pose
  world_state = { {0, 0, 1, 0, 0, 0},
                  {0, 0, 1, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0},
                  {0, 0, 0, 0, 1, 0},
                  {0, 0, 1, 1, 1, 0},
                  {0, 0, 0, 0, 0, 0} };
  robot_pose.x = -1;
  cout << "\nTest invalid robot_pose:" << endl;
  test(world_state, robot_pose, goal_pose, random_planner, optimal_planner);

  // invalid goal_pose
  robot_pose.x = 2;
  goal_pose.x = 18;
  cout << "\nTest invalid goal_pose:" << endl;
  test(world_state, robot_pose, goal_pose, random_planner, optimal_planner);

  // general case: path exists
  goal_pose.x = 5;
  cout << "\nTest when path exists:" << endl;
  test(world_state, robot_pose, goal_pose, random_planner, optimal_planner);

  // general case: path exists
  world_state = { {0, 0, 1, 0, 0, 0},
                  {0, 0, 1, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0},
                  {0, 0, 0, 0, 1, 0},
                  {0, 0, 1, 1, 1, 0},
                  {0, 0, 1, 0, 0, 0} };
  cout << "\nTest when path exists:" << endl;
  test(world_state, robot_pose, goal_pose, random_planner, optimal_planner);

  // general case: path does not exist
  world_state = { {0, 0, 1, 0, 0, 0},
                  {0, 0, 1, 0, 0, 0},
                  {0, 0, 1, 0, 1, 0},
                  {0, 0, 1, 0, 1, 0},
                  {0, 0, 1, 1, 1, 0},
                  {0, 0, 1, 0, 0, 0} };
  cout << "\nTest when path does not exist:" << endl;
  test(world_state, robot_pose, goal_pose, random_planner, optimal_planner);

  return 0;
}

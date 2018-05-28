#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>

using namespace std;
const int max_step_number = 100;

struct Location {
  int x;
  int y;
  Location():x(-1), y(-1) {}
  Location(int x, int y): x(x), y(y) {}
  bool operator== (const Location& other) const{
    if(x == other.x && y == other.y) {
      return true;
    }
    return false;
  }
  bool operator< (const Location& other) const{
    if(x < other.x){
      return true;
    }
    else if(x > other.x) {
      return false;
    }
    else {
      if(y < other.y) {
        return true;
      }
      else {
        return false;
      }
    }
  }
};

class Random_planner {
public:
  /**
    Find the path from robot_pose to goal_pose in a given world_state by
          random moving

    @param world_state 2D-grid representation of the environment, 0
              indicates a navigable space, 1 indicates an occupied/obstacle space.
    @param robot_pose Current pose of the robot in world_state.
    @param goal_pose The goal poas in the world_state.
    @return path A path from the robot_pose to the goal_pose in world_state or {} if no path found.
  */
  vector<Location> search(vector< vector<int> > world_state, Location robot_pose, Location goal_pose);

private:
  /**
    Check whether a given position is inside x_boundary and y_boundary

    @param pos The Location to be checked
    @param x_boundary The x boundary
    @param y_boundary The y boundary
    @return is_valid True if the pos is valid, else false
  */
  inline bool is_pos_valid(Location pos, int x_boundary, int y_boundary) {
    bool is_valid = pos.x >= 0 && pos.x < x_boundary && pos.y >= 0 && pos.y < y_boundary;
    return is_valid;
  }
};

class Optimal_planner {
public:
  /**
    Find the optimal path from robot_pose to goal_pose in a given world_state
    using A* algorithm

    @param world_state 2D-grid representation of the environment, 0 indicates
          a navigable space, 1 indicates an occupied/obstacle space.
    @param robot_pose Current pose of the robot in world_state.
    @param goal_pose The goal poas in the world_state.
    @return path A path from the robot_pose to the goal_pose in world_state or
            {} if no path found.
  */
  vector<Location> search(vector< vector<int> > world_state, Location robot_pose, Location goal_pose);

private:
  /**
    Compute the manhattan distance between two Locations

    @param a The starting Location
    @param b The ending Location
    @return the heuristic distance between location a and b
  */
  inline int heuristic(Location a, Location b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
  }
  /**
    Check whether a given position is inside x_boundary and y_boundary

    @param pos The Location to be checked
    @param x_boundary The x boundary
    @param y_boundary The y boundary
    @return is_valid True if the pos is valid, else false
  */
  inline bool is_pos_valid(Location pos, int x_boundary, int y_boundary) {
    bool is_valid = pos.x >= 0 && pos.x < x_boundary && pos.y >= 0 && pos.y < y_boundary;
    return is_valid;
  }
};

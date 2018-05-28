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
  vector<Location> search(vector< vector<int> > world_state, Location robot_pose, Location goal_pose);

private:
  inline bool is_pos_valid(Location pos, int x_boundary, int y_boundary) {
    bool is_valid = pos.x >= 0 && pos.x < x_boundary && pos.y >= 0 && pos.y < y_boundary;
    return is_valid;
  }
};

class Optimal_planner {
public:
  vector<Location> search(vector< vector<int> > world_state, Location robot_pose, Location goal_pose);

private:
  inline int heuristic(Location a, Location b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
  }

  inline bool is_pos_valid(Location pos, int x_boundary, int y_boundary) {
    bool is_valid = pos.x >= 0 && pos.x < x_boundary && pos.y >= 0 && pos.y < y_boundary;
    return is_valid;
  }
};

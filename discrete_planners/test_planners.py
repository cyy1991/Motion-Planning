import random_planner
import optimal_planner
import numpy as np

# edge cases
# empty world_state
world_state = np.matrix([[]])
robot_pose = (2, 0)
goal_pose = (5, 5)
print("\nTest empty world_state:")
print "Random_planner:\n", random_planner.search(world_state, robot_pose, goal_pose)
print "Optimal_planner:\n", optimal_planner.search(world_state, robot_pose, goal_pose)

# invalid robot_pose
world_state = np.matrix( [[0, 0, 1, 0, 0, 0],
                          [0, 0, 1, 0, 0, 0],
                          [0, 0, 0, 0, 1, 0],
                          [0, 0, 0, 0, 1, 0],
                          [0, 0, 1, 1, 1, 0],
                          [0, 0, 0, 0, 0, 0]] )
robot_pose = (-1, 0)
goal_pose = (5, 5)
print("\nTest invalid robot_pose:")
print "Random_planner:\n", random_planner.search(world_state, robot_pose, goal_pose)
print "Optimal_planner:\n", optimal_planner.search(world_state, robot_pose, goal_pose)

# invalid goal_pose
robot_pose = (2, 0)
goal_pose = (9, 10)
print("\nTest invalid goal_pose:")
print "Random_planner:\n", random_planner.search(world_state, robot_pose, goal_pose)
print "Optimal_planner:\n", optimal_planner.search(world_state, robot_pose, goal_pose)



robot_pose = (2, 0)
goal_pose = (5, 5)
print("\nTest when path exists:")
print "Random_planner:\n", random_planner.search(world_state, robot_pose, goal_pose)
print "Optimal_planner:\n", optimal_planner.search(world_state, robot_pose, goal_pose)
assert optimal_planner.search(world_state, robot_pose, goal_pose) == ([(2, 0),
        (2, 1), (3, 1), (4, 1), (5, 1), (5, 2), (5, 3), (5, 4), (5, 5)])

world_state = np.matrix( [[0, 0, 1, 0, 0, 0],
                          [0, 0, 1, 0, 0, 0],
                          [0, 0, 0, 0, 1, 0],
                          [0, 0, 0, 0, 1, 0],
                          [0, 0, 1, 1, 1, 0],
                          [0, 0, 1, 0, 0, 0]] )

print("\nTest when path exists:")
print "Random_planner:\n", random_planner.search(world_state, robot_pose, goal_pose)
print "Optimal_planner:\n", optimal_planner.search(world_state, robot_pose, goal_pose)
assert optimal_planner.search(world_state, robot_pose, goal_pose) == ([(2, 0),
        (2, 1), (2, 2), (2, 3), (1, 3), (1, 4), (1, 5), (2, 5), (3, 5), (4, 5),
        (5, 5)])

world_state = np.matrix( [[0, 0, 1, 0, 0, 0],
                          [0, 0, 1, 0, 0, 0],
                          [0, 0, 1, 0, 1, 0],
                          [0, 0, 1, 0, 1, 0],
                          [0, 0, 1, 1, 1, 0],
                          [0, 0, 1, 0, 0, 0]] )
print("\nTest when path does not exist:")
print "Random_planner:\n", random_planner.search(world_state, robot_pose, goal_pose)
print "Optimal_planner:\n", optimal_planner.search(world_state, robot_pose, goal_pose)

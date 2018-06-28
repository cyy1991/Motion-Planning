import random_planner
import optimal_planner
import numpy as np
import time

def test(world_state, robot_pose, goal_pose):
    time1 = time.time()
    print("\tRandom_planner:\n\t", random_planner.search(world_state, robot_pose, goal_pose))
    print("\tUsed time:", time.time() - time1)
    time1 = time.time()
    print("\tOptimal_planner:\n\t", optimal_planner.search(world_state, robot_pose, goal_pose))
    print("\tUsed time:", time.time() - time1)


def display(world_state, robot_pose, goal_pose):
    print("Given matrix:")
    print(world_state)
    print("Robot pose:", robot_pose, end="\t")
    print("Goal pose:", goal_pose)


def main():
    # edge cases
    # empty world_state
    world_state = np.matrix([[]])
    robot_pose = (2, 0)
    goal_pose = (5, 5)
    print("\nTest empty world_state:")
    display(world_state, robot_pose, goal_pose)
    test(world_state, robot_pose, goal_pose)

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
    display(world_state, robot_pose, goal_pose)
    test(world_state, robot_pose, goal_pose)

    # invalid goal_pose
    robot_pose = (2, 0)
    goal_pose = (9, 10)
    print("\nTest invalid goal_pose:")
    display(world_state, robot_pose, goal_pose)
    test(world_state, robot_pose, goal_pose)

    robot_pose = (2, 0)
    goal_pose = (5, 5)
    print("\nTest when path exists:")
    display(world_state, robot_pose, goal_pose)
    test(world_state, robot_pose, goal_pose)
    assert optimal_planner.search(world_state, robot_pose, goal_pose) == ([(2, 0),
            (2, 1), (3, 1), (4, 1), (5, 1), (5, 2), (5, 3), (5, 4), (5, 5)])

    world_state = np.matrix( [[0, 0, 1, 0, 0, 0],
                              [0, 0, 1, 0, 0, 0],
                              [0, 0, 0, 0, 1, 0],
                              [0, 0, 0, 0, 1, 0],
                              [0, 0, 1, 1, 1, 0],
                              [0, 0, 1, 0, 0, 0]] )

    print("\nTest when path exists:")
    display(world_state, robot_pose, goal_pose)
    test(world_state, robot_pose, goal_pose)
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
    display(world_state, robot_pose, goal_pose)
    test(world_state, robot_pose, goal_pose)

if __name__ == "__main__":
    main()

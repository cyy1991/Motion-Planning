import numpy as np
import math
# from collections import deque # use deque to improve speed
max_step_number = 100 # maximum steps for the planner to search

def is_pos_valid(pos, shape):
    """ check whether a position is valid

    Args:
        pos (tuple): coordinate of pos
    Returns:
        is_valid (bool): True for valid pos, False for invalid pos
    """
    x, y = pos
    is_valid = x >= 0 and x < shape[0] and y >= 0 and y < shape[1]
    return is_valid


# TODO delete unnecessary print statements
def search(world_state, robot_pose, goal_pose):
    """ find the path from robot_pose to goal_pose in a given world_state by
        random moving

    Args:
        world_state (np 2d array): 2D-grid representation of the environment, 0
            indicates a navigable space, 1 indicates an occupied/obstacle space.
        robot_pose (tuple): current pose of the robot in world_state.
        goal_pose (tuple): the goal poas in the world_state.
    Returns:
        path (list of tuple): a path from the robot_pose to the goal_pose in
            world_state or None if no path found.
    """
    if world_state.shape[0] == 0 or world_state.shape[1] == 0:
        print "Error, empty world_state!!!"
        return None
    if not is_pos_valid(robot_pose, world_state.shape):
        print "Error, invalid robot_pose!!!", robot_pose
        return None
    if not is_pos_valid(goal_pose, world_state.shape):
        print "Error, invalid goal_pose!!!", goal_pose
        return None

    current = robot_pose
    recent_visted = [] # deque()
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)] # orthogonal directions
    path = []
    found = False
    steps = 0
    steps_boundary = int(math.sqrt(max_step_number))

    while steps < max_step_number:
        path.append(current)
        # update recent_visted
        if len(recent_visted) == steps_boundary:
            # recent_visted.popleft()
            recent_visted.pop(0)
        recent_visted.append(current)
        # print steps, recent_visted

        if current == goal_pose:
            found = True
            break
        np.sqrt(max_step_number)

        available_positions = []
        not_visited = [] # store available positions which are not visited
        # find available next positions
        for direction in directions:
            x = current[0] + direction[0]
            y = current[1] + direction[1]
            # check whether x and y are valid
            if not is_pos_valid((x, y), world_state.shape):
                continue

            if world_state[x, y] == 0:
                available_positions.append((x, y))
                if (x, y) not in recent_visted:
                    not_visited.append((x, y))

        # randomly pick one position that was not visited in the last
        # sqrt(max_step_number) steps except if this is the only available option
        if len(available_positions) < 1: # if the robot is stuck inside obstacles
            break
        elif len(available_positions) == 1:
            current = available_positions[0]
        else:
            # if all available positions are not visited or all of them are visited
            if len(not_visited) == len(available_positions) or len(not_visited) == 0:
                idx = np.random.choice(len(available_positions))
                current = available_positions[idx]
            else:
                idx = np.random.choice(len(not_visited))
                current = not_visited[idx]

        steps += 1

    return path if found else None

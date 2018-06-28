import numpy as np


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


def heuristic(p1, p2):
    """ return the manhattan distance as heuristic

    Args:
        p1 (tuple): coordinate of position 1
        p2 (tuple): coordinate of position 2
    Returns:
        heuristic (int): computed heuristic value
    """
    x1, y1 = p1
    x2, y2 = p2
    heuristic = abs(x1 - x2) + abs(y1 - y2)
    return heuristic


def search(world_state, robot_pose, goal_pose):
    """ find the optimal path from robot_pose to goal_pose in a given world_state
        using A* algorithm

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
        print("Error, empty world_state!!!")
        return None
    if not is_pos_valid(robot_pose, world_state.shape):
        print("Error, invalid robot_pose!!!", robot_pose)
        return None
    if not is_pos_valid(goal_pose, world_state.shape):
        print("Error, invalid goal_pose!!!", goal_pose)
        return None

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)] # orthogonal directions
    found = False

    x, y = robot_pose
    g = 0
    h = heuristic(robot_pose, goal_pose)
    f = g + h
    open = [[f, x, y]]
    came_from = {}
    came_from[robot_pose] = None
    cost_so_far = {}
    cost_so_far[robot_pose] = 0

    while open:
        open.sort() # sort based on f value
        current = open.pop(0)

        x, y = current[1:]
        g = cost_so_far[(x, y)]

        if (x, y) == goal_pose:
            found = True
            break
        else:
            # find available next positions
            for direction in directions:
                x2 = x + direction[0]
                y2 = y + direction[1]

                # check whether x2 and y2 are valid
                if not is_pos_valid((x2, y2), world_state.shape):
                    continue

                g2 = g + 1
                if world_state[x2, y2] == 0 and ((x2, y2) not in cost_so_far or g2 < cost_so_far[(x2, y2)]):

                    h2 = heuristic((x2, y2), goal_pose)
                    f2 = g2 + h2
                    open.append([f2, x2, y2])
                    came_from[(x2, y2)] = (x, y)
                    cost_so_far[(x2, y2)] = g2
    if found:
        path = [goal_pose]
        current = goal_pose
        while came_from[current]:
            current = came_from[current]
            path.append(current)

        path.reverse()
        return path

    else:
        return None

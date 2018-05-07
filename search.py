# ----------
# User Instructions:
#
# Define a function, search() that returns a list
# in the form of [optimal path length, row, col]. For
# the grid shown below, your function should output
# [11, 4, 5].
#
# If there is no valid path from the start point
# to the goal, your function should return the string
# 'fail'
# ----------

# Grid format:
#   0 = Navigable space
#   1 = Occupied space
from pprint import pprint
grid = [[0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 1, 0],
        [0, 0, 1, 1, 1, 0],
        [0, 0, 0, 0, 1, 0]]
init = [0, 0]
goal = [len(grid)-1, len(grid[0])-1]
cost = 1

delta = [[-1, 0], # go up
         [ 0,-1], # go left
         [ 1, 0], # go down
         [ 0, 1]] # go right

delta_name = ['^', '<', 'v', '>']

def search(grid,init,goal,cost):
    # ----------------------------------------
    # insert code here
    # ----------------------------------------
    # open list elements are of type: [g, x, y]
    # 0: open, 1: closed
    closed = [[0 for col in range(len(grid[0]))] for row in range(len(grid))]
    closed[init[0]][init[1]] = 1

    x = init[0]
    y = init[1]
    g = 0

    open = [[g, x, y]]

    found = False # flag that is set when search complete
    resign = False # flag set if we can't find expand

    # print 'initial open list'
    # for i in range(len(open)):
        # print '    ', open[i]
    # print '-----'

    while found is False and resign is False:
        # check if we still have elements in the open list
        if len(open) == 0:
            resign = True
            # print 'fail'
            path = 'fail'


        else:
            # remove node from list
            open.sort()
            open.reverse()
            next = open.pop()

            # print 'take list item'
            # print next
            x = next[1]
            y = next[2]
            g = next[0]

            if x == goal[0] and y == goal[1]:
                found = True
                path = next
                # print next

            else:
                # expand winning element and add to new open list
                for i in range(len(delta)):
                    x2 = x + delta[i][0]
                    y2 = y + delta[i][1]

                    if x2 >= 0 and x2 < len(grid) and y2 >= 0 and y2 < len(grid[0]):
                        # not yet checked, and not an obstacle
                        if closed[x2][y2] == 0 and grid[x2][y2] == 0:
                            g2 = g + cost
                            open.append([g2, x2, y2])

                            closed[x2][y2] = 1
    return path

def search1(grid, init, goal, cost):
    closed = [[0 for col in range(len(grid[0]))] for row in range(len(grid))]
    expand = [[-1 for col in range(len(grid[0]))] for row in range(len(grid))]
    actions = [[-1 for col in range(len(grid[0]))] for row in range(len(grid))]

    closed[init[0]][init[1]] = 1

    x = init[0]
    y = init[1]
    g = 0

    open = [[g, x, y]]
    accu = 0
    expand[0][0] = accu

    while open:
        open.sort()
        open.reverse()
        next = open.pop()

        g, x, y = next
        if x == goal[0] and y == goal[1]:
            # return next
            print("found")
        else:
            for i in range(len(delta)):
                x2 = x + delta[i][0]
                y2 = y + delta[i][1]
                if x2 >= 0 and x2 < len(grid) and y2 >= 0 and y2 < len(grid[0]):
                    if closed[x2][y2] == 0 and grid[x2][y2] == 0:
                        g2 = g + cost
                        open.append([g2, x2, y2])
                        closed[x2][y2] = 1

                        accu += 1
                        expand[x2][y2] = accu
                        actions[x2][y2] = i
    policy = [[" " for col in range(len(grid[0]))] for row in range(len(grid))]
    x, y = goal
    policy[x][y] = "*"

    step = 1
    steps = [[" " for col in range(len(grid[0]))] for row in range(len(grid))]

    while x != init[0] or y != init[1]:
        action = actions[x][y]

        x2 = x - delta[action][0]
        y2 = y - delta[action][1]

        policy[x2][y2] = delta_name[action]
        step += 1

        x = x2
        y = y2

    x, y = goal
    steps[x][y] = step
    while x != init[0] or y != init[1]:
        action = actions[x][y]

        x2 = x - delta[action][0]
        y2 = y - delta[action][1]

        step -= 1
        steps[x2][y2] = step

        x = x2
        y = y2
    # return "fail"
    # return expand
    pprint(expand)
    pprint(steps)

    return policy
print(search(grid,init,goal,cost))
pprint(search1(grid,init,goal,cost))

''' 
A wall consists of several rows of bricks of various integer length and uniform height. Goal is to find a vertical line going from the top to the bottom of the wall that cuts through the fewest number of bricks. If the line goes through the edge between two bricks, this does not count as a cut.

Idea: Instead of minimizing the number of cuts, try to maximize the number of times a line can pass through an edge between two bricks.
'''
from collections import defaultdict

def fewest_cuts(wall):
    cuts = defaultdict(int)
    
    for row in wall:
        length = 0
        for brick in row[:-1]:
            length += brick
            cuts[length] += 1
            
    max_cuts = max(cuts.values())
    key = [k for k,v in cuts.items() if v == max_cuts]
    return (len(wall) - max_cuts, key)

wall = [[3,5,1,1],
        [2,3,3,2],
        [5,5],
        [4,4,2],
        [1,3,3,3],
        [1,1,6,1,1]]

req_cuts, position = fewest_cuts(wall)
print(f"Fewest cuts required are {req_cuts} at length {position}")

''' 
Output:

Fewest cuts required are 2 at length [8]
'''
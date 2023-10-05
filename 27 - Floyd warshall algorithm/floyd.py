INF = float('inf')
def printmatrix(m):
    r,c = len(m),len(m[0])
    for i in range(r):
        for j in range(c):
            print(m[i][j],end=" ")
        print()

v,e = map(int,input().split())
m = [[0]*v for i in range(v)]
for i in range(v):
    for j in range(v):
        if i == j:
            m[i][j] = 0
        # edge doesn't exist
        else:
            m[i][j] = INF

for i in range(e):
    src,dst,wt = map(int,input().split())
    m[src][dst] = wt

printmatrix(m)
print("-------------------")
# find shortest path using Floyd Warshall algorithm
for k in range(v):
    for i in range(v):
        for j in range(v):
            # cost of temp path is less update it
            if m[i][k]+m[k][j] < m[i][j]:
                m[i][j] = m[i][k] + m[k][j]
printmatrix(m)
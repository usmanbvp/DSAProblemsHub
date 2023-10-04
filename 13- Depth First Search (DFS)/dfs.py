# DFS implementation to search from source vertex to destination vertex
def dfs(G,s,d):
    stack = []
    visited_nodes = []
    stack.append(s)
    visited_nodes.append(s)
    print(f"DFS search from {s} to {d}: ")
    while stack:
        s = stack.pop()
        print(s)
        if s == d:
            break
        for neighbor in G[s]:
            if neighbor not in visited_nodes:
                stack.append(neighbor)
                visited_nodes.append(neighbor)


# Creates the undirected graph using adjacency list from the user input
graph_adj_list = {}

total_nodes = int(input("Enter total nodes: "))
for i in range(total_nodes):
    node = int(input("Enter node: "))
    graph_adj_list[node] = list(map(int,input("Enter neighbors: ").split()))

print("Graph is ",graph_adj_list)

# Calls DFS with source vertex and destination vertex
source_vertex = int(input("Enter source vertex:"))
destination_vertex = int(input("Enter destination vertex:"))
dfs(graph_adj_list,source_vertex,destination_vertex)


'''
Input/Output:

Enter total nodes: 6
Enter node: 1
Enter neighbors: 2 3
Enter node: 2
Enter neighbors: 1 4
Enter node: 3
Enter neighbors: 1 4 5 6
Enter node: 4
Enter neighbors: 2 3 5
Enter node: 5
Enter neighbors: 3 4
Enter node: 6
Enter neighbors: 3
Graph is  {1: [2, 3], 2: [1, 4], 3: [1, 4, 5, 6], 4: [2, 3, 5], 5: [3, 4], 6: [3]}
Enter source vertex:1
Enter destination vertex:6
DFS search from 1 to 6:
1
3
6

'''
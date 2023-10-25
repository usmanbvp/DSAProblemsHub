import heapq

def prim_mst(graph):
    visited = set()
    min_spanning_tree = []
    start_node = list(graph.keys())[0]

    def add_edges(node):
        visited.add(node)
        for neighbor, weight in graph[node]:
            if neighbor not in visited:
                heapq.heappush(min_spanning_tree, (weight, node, neighbor))

    add_edges(start_node)

    while min_spanning_tree:
        weight, u, v = heapq.heappop(min_spanning_tree)
        if v not in visited:
            min_spanning_tree.append((weight, u, v))
            add_edges(v)

    return min_spanning_tree

def main():
    graph = {}
    num_edges = int(input("Enter the number of edges: "))

    for _ in range(num_edges):
        u, v, weight = map(int, input("Enter edge (u v weight): ").split())
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append((v, weight))
        graph[v].append((u, weight))

    minimum_spanning_tree = prim_mst(graph)
    
    print("Minimum Spanning Tree:")
    total_weight = 0
    for weight, u, v in minimum_spanning_tree:
        print(f"{u} -- {v} : {weight}")
        total_weight += weight
    print(f"Total Weight of Minimum Spanning Tree: {total_weight}")

if __name__ == "__main__":
    main()

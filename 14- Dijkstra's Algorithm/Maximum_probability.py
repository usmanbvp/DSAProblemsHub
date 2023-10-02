'''PROBLEM : You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an
undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.8'''

#Code
import heapq
from typing import List

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = [[] for _ in range(n)]
        for i, (a, b) in enumerate(edges):
            prob = succProb[i]
            graph[a].append((b, prob))
            graph[b].append((a, prob))

        # Initialize a priority queue (min-heap) with the starting node and its probability
        pq = [(-1.0, start_node)]
        visited = [False] * n

        while pq:
            prob, node = heapq.heappop(pq)
            prob = -prob  # Get the positive probability back
            if visited[node]:
                continue
            visited[node] = True
            if node == end_node:
                return prob
            for neighbor, neighbor_prob in graph[node]:
                if not visited[neighbor]:
                    new_prob = prob * neighbor_prob
                    heapq.heappush(pq, (-new_prob, neighbor))

        return 0.0

# Example usage:
n1 = 3
edges1 = [[0, 1], [1, 2], [0, 2]]
succProb1 = [0.5, 0.5, 0.2]
start1 = 0
end1 = 2

sol = Solution()
print(sol.maxProbability(n1, edges1, succProb1, start1, end1))  # Output: 0.25

        

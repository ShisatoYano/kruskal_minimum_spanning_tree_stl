# kruskal_minimum_spanning_tree_stl

* Implementing Kruskal's algorithm using STL.  

1. Sort all edges in non-decreasing order of their weight.  
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.  
3. If cycle is not formed, include this edge. Else, discard it.  
4. Repeat step #2 until there are (V-1) edges in the spanning tree.  

* Use a vector of edges which consist of all the edges in the graph and item of a vector will contain 3 parameters  
* source, destination and the cost of an edge
* Use the inbuilt std::sort to sort the edges in the non-decreasing order
* Use Union Find Algorithm to check if it the current edge forms a cycle if it is added in the current MST.  


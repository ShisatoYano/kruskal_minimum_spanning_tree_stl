#include <bits/stdc++.h>
using namespace std;

// integer pair
typedef pair<int, int> i_pair;

// structure of graph
struct Graph {
    int V, E;
    vector<pair<int, i_pair>> edges;

    // constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // add an edge
    void add_edge(int s, int d, int w) {
        edges.push_back({w, {s, d}});
    }

    // find minimum spanning tree
    // using kruskal's algorithm
    int kruskal_minimum_spanning_tree();
};

// disjoint sets
struct DisjointSets {
    int *parent, *rank;
    int n;

    // constructor
    DisjointSets(int n) {
        // allocate memory
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        // all vertices are in different sets
        for (int i = 0; i <= n; ++i) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    // find the parent of node s
    // path compression
    int find(int s) {
        // make the parent of the nodes in the path
        // from s--> parent[s] point to parent[s]
        if (s != parent[s]) {
            parent[s] = find(parent[s]);
        }
        return parent[s];
    }

    // union by rank
    void merge(int x, int y) {
        x = find(x), y = find(y);

        // make tree with smaller height
        // s subtree of the other tree
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

// returns weight of minimum spanning tree
int Graph::kruskal_minimum_spanning_tree() {
    int min_w = 0;

    // sort edges in increasing order on basis of weight
    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    // iterate through all sorted edges
    vector<pair<int, i_pair>>::iterator it;
    for (it = edges.begin(); it!=edges.end(); it++) {
        int s = it->second.first;
        int d = it->second.second;

        int set_s = ds.find(s);
        int set_d = ds.find(d);

        // check if the selected edge is creating
        // a cycle or not
        if (set_s != set_d) {
            cout << s << " - " << d << endl;

            min_w += it->first;

            ds.merge(set_s, set_d);
        }
    }

    return min_w;
}

int main() {
    int V = 9, E = 14;
    Graph g(V, E);

    // making graph
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    cout << "Edges of Minimum Spanning Tree\n";
    int min_w = g.kruskal_minimum_spanning_tree();

    cout << "\nMinimum Weight is " << min_w;

    return 0;
}

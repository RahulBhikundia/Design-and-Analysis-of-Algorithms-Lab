/*Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, rank, size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    int vertices;
    cout << "Enter the number of vertices:";
    cin >> vertices;
    vector<int> visited(vertices, 0);

    // Taking weighted undirected edges in adjacency matrix format as an input from user, where 0 represent no edge
    cout << "Enter Adjacency Matrix for the diagraph:" << endl;
    vector<vector<int>> adjM(vertices, vector<int>(vertices, 0));
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> adjM[i][j];
        }
    }

    // Creating a structure to store {edges, {src, dst}}
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adjM[i][j] != 0)
                edges.push_back({adjM[i][j], {i, j}});
        }
    }

    DisjointSet ds(vertices);
    sort(edges.begin(), edges.end());
    int mstwt = 0;
    for(auto it: edges) {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)) {
            mstwt += w;
            ds.unionBySize(u, v);
        }
        else {
            adjM[u][v] = 0;
        }
    }

    cout<< "The sum of all the edge weights: "<< mstwt << endl;
    cout<< "The minimum spannig tree is:" << endl;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<< adjM[i][j] <<" ";
        }
        cout<<endl;
    }

    return 0;
}
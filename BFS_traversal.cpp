/*
a. Print all the nodes reachable from a given starting node in a digraph using BFS method.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int vertices;
    cout << "Enter the number of vertices:";
    cin >> vertices;
    vector<int> visited(vertices, 0);
    // Defining directed edges in adjacency matrix

    cout << "Enter Adjacency Matrix for the diagraph:" << endl;
    vector<vector<int>> adjM(vertices, vector<int>(vertices, 0));
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> adjM[i][j];
        }
    }

    int sourceN;
    cout<<"Enter Starting Node: ";
    cin>>sourceN;

    queue<int> q;
    q.push(sourceN);
    visited[sourceN] = 1;
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        bfs.push_back(node);
        q.pop();
        for (int i = 0; i < vertices; i++)
        {
            if (adjM[node][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    cout << "Nodes reachable from source node: ";
    for (auto node : bfs)
        cout << node << " ";

    return 0;
}
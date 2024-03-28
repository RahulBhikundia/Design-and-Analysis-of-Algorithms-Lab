/*
b. Check whether a given graph is connected or not using DFS method.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, vector<vector<int>>& adjM, vector<int>& visited, vector<int>& ans) {
    visited[node] = 1;
    ans.push_back(node);
    for(int i=0;i<adjM.size();i++){
        if(adjM[node][i] == 1 && !visited[i])
            dfs(i,adjM,visited,ans);
    }
}

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

    vector<int> ans;

    dfs(0,adjM,visited,ans);

    if(ans.size() == vertices) cout<<"Graph is connected";
    else cout<<"Graph is not connected";

    return 0;
}
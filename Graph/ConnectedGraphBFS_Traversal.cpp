#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

void createAdjacencyList(vector<pair<int, int>> &edges, vector<vector<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfsForConnectedGraph(vector<vector<int>> &adjList, unordered_map<int, bool> &visited, int s)
{
    vector<int> ans;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto x : adjList[f])
        {
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
    // printing bfs---------------------
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void bsfForDisconnected(vector<vector<int>> &adjList, int V)
{
    unordered_map<int, bool> visited;
    vector<int> part;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            bfsForConnectedGraph(adjList, visited, i);
    }
}

int main()
{
    int V = 7;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 2}, {0, 3}, {1, 2}, {4, 5}, {5, 6}, {4, 6}, {4, 4}};
    vector<vector<int>> adjList(V);
    unordered_map<int, bool> visited;
    int s = 0; // source vertex

    // Create Adjacency List----------------
    createAdjacencyList(edges, adjList);
    // If graph is connected
    // bfsForConnectedGraph(adjList, visited, s);

    // if graph is disconnected------------
    bsfForDisconnected(adjList, V);

    return 0;
}

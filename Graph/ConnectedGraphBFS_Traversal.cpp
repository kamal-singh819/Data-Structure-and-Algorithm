#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

//Create  Adjacency List using vector of vector
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

//bfs traversal------------------
vector<int> bfsForConnectedGraph(vector<vector<int>> &adjList, int V, int s)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
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
    return ans;
}

int main()
{
    int V = 6;  //no. of vertices
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}};
    vector<vector<int>> adjList(V);
    int s = 0; // source vertex

    // Create Adjacency List----------------
    createAdjacencyList(edges, adjList);

    vector<int> ans;
    ans = bfsForConnectedGraph(adjList, V, s);
    // printing bfs---------------------
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

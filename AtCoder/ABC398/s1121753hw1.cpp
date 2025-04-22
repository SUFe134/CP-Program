#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

vector<int> adjacencyList[10];
bool visited[10];

void find_cycles(int v, int start, vector<int>& path, set<vector<int>>& seenCycles)
{
    visited[v] = true;
    path.push_back(v);

    for (int neighbor : adjacencyList[v])
    {
        if (!visited[neighbor])
            find_cycles(neighbor, start, path, seenCycles);
        else if (neighbor == start && path.size() > 2)
        {
            vector<int> cycle(path.begin(), path.end());
            sort(cycle.begin(), cycle.end());
            seenCycles.insert(cycle);
        }
    }

    visited[v] = false;
    path.pop_back();
}

bool is_connected(int n)
{
    for (int i = 1; i <= n; ++i)
        visited[i] = false;

    int startNode = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (!adjacencyList[i].empty())
        {
            startNode = i;
            break;
        }
    }

    if (startNode == -1) return false;

    vector<int> stack;
    stack.push_back(startNode);
    visited[startNode] = true;

    while (!stack.empty())
    {
        int node = stack.back();
        stack.pop_back();

        for (int neighbor : adjacencyList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                stack.push_back(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        if (!adjacencyList[i].empty() && !visited[i])
            return false;

    return true;
}

void output(int numCycles)
{
    if (numCycles == 0 || numCycles == 1)
        cout << "n" << endl;
    else if (numCycles == 2)
        cout << "y" << endl;
    else
    {
        cout << "y" << endl;
        cout << "There are at least three cycles." << endl;
    }
}

int main()
{
    set<vector<int>> cycleSet;
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        adjacencyList[i].clear();

    int u, v;
    while (cin >> u && u != -1)
    {
        cin >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    if (is_connected(n))
    {
        for (int i = 1; i <= n; ++i)
            visited[i] = false;
        cycleSet.clear();
        set<vector<int>> seenCycles;

        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i] && !adjacencyList[i].empty())
            {
                vector<int> path;
                find_cycles(i, i, path, seenCycles);
            }
        }

        output(seenCycles.size());
    }
    else
        cout << "n" << endl;

    return 0;
}

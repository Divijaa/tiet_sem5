#include <bits/stdc++.h>
using namespace std;
//bfs approach kahn's algo 
//o(v+e)
int main()
{
    int n, m;
    cout << "Enter the number of vertices and number of edges" << endl;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    vector<int> indeg(n, 0);

//taking input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u --> v
        adj_list[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for (int i = 0; i < n; i++)
    {
    	//pushing those jinki indegree 0 hai
        if (indeg[i] == 0)
            pq.push(i);
    }
    vector<int>::iterator itr;

    int cnt = 0;
    vector<int> topo_sort;

    while (!pq.empty())
    {
        cnt++;
        int x = pq.front();
        pq.pop();
        topo_sort.push_back(x);
        for (itr = adj_list[x].begin(); itr < adj_list[x].end(); itr++)
        {
            indeg[*itr]--;
            if (indeg[*itr] == 0)
            {
                pq.push(*itr);
            }
        }
    }

    if (cnt != n)
    {
        cout << "There exists a cycle in a graph" << endl;
        return 0;
    }

    for (int i = 0; i < topo_sort.size(); i++)
    {
        cout << topo_sort[i] << " ";
    }
    return 0;
}

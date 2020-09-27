#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000;
const int INF = 1<<27;

vector<int> grp[MAX], weight[MAX];
int cost[MAX];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.push({0,src}); // [cost, node]
    cost[src] = 0;
    while(!Q.empty())
    {
        int x = Q.top().second;
        int y = Q.top().first;
        Q.pop();
        if (cost[x] < y) continue;
        
        for(int i = 0; i < grp[x].size(); i++)
        {
            int to = grp[x][i];
            if(cost[to] > cost[x] + weight[x][i])
            {
                cost[to] = cost[x] + weight[x][i];
                Q.push({cost[to], to});
            }
        }
    }

}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        grp[u].emplace_back(v);
        grp[v].emplace_back(u);
        weight[u].emplace_back(w);
        weight[v].emplace_back(w);
    }
    fill(cost, cost+node, INF);
    int src, dest;
    cin >> src >> dest;
    dijkstra(src);
    cout << cost[dest] << endl;

    return 0;
}

//Problem 1 (Direct Dijkstra): https://codeforces.com/contest/20/problem/C
//Solution 1: http://codeforces.com/contest/20/submission/39892416

//Problem 2: http://codeforces.com/contest/230/problem/D
//Solution 2: http://codeforces.com/contest/230/submission/39892295

//Problem 3 (count point on edges): https://codeforces.com/problemset/problem/144/D
//Solution 3: https://codeforces.com/contest/144/submission/45963496

//Problem 4 (all source Dijkstra): https://codeforces.com/contest/96/problem/D
//Solution 4: https://codeforces.com/contest/96/submission/45959572

//Problem 5: https://p.ip.fi/woUJ (Lexicographically shortest path from U to V)
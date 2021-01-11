#include <local.h>

// dfs generic structure
void dfs(int s)
{
    vis[s] = true;
    for(auto &it : graph[s])
        if(vis[it] == false)
            dfs(it);
}


// find shortest path from source to all node
void dfs(int s, int level = 0)
{
    vis[s] = 1;
    dist[s] = min(dist[s], level);
    for(auto it : graph[s])
        if(vis[it] == 0 || (vis[it] == 1 && dist[it] > level + 1))
            dfs(it, level + 1);
}


// get number of leaf nodes in every subtree of a rooted tree
int cnt[N];
void dfs(int s, int par = -1) {
	if (graph[s].size() == 1)
        cnt[par] = 1;
	for (auto child : graph[s]) {
        if (child == par)
            continue;
		dfs(child, s);
		if (par != -1)
            cnt[par] += cnt[child];
	}
}


// is it possible to go from (x, y) to (dist_x, dist_y)?
bool dfs(int x,int y,int dest_x,int dest_y)
{
    if(x==dest_x && y==dest_y) return true;
    if((x<0 || y<0 || x>n || y>m) || mat[x][y]==0 || vis[x][y]==true) return false;

    vis[x][y] = true;

    if(dfs(x+1, y, dest_x, dest_y) == true) return true;
    if(dfs(x, y+1, dest_x, dest_y) == true) return true;
    if(dfs(x-1, y, dest_x, dest_y) == true) return true;
    if(dfs(x, y-1, dest_x, dest_y) == true) return true;

    return false;
}


//problem_1 (finding specific size path in 2d string maze): https://codeforces.com/problemset/problem/377/A
//solution_1: https://codeforces.com/contest/377/submission/89995748
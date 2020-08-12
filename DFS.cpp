// dfs structure
void dfs(int s)
{
    visited[s] = true;
    for(auto &it : graph[s])
    {
        if(visited[it] == false)
        {
            dfs(it);
        }
    }
}


// find distance of all nodes from a node 
void dfs(int s, int level)
{
    visited[s] = 1;
    dist[s] = level;
    for(auto it : graph[s])
    {
        if(visited[it]==0)
        {
            dfs(it, level+1);
        }
    }
}


// is it possible to go from (x, y) to (dist_x, dist_y)?
bool dfs(int x,int y,int dest_x,int dest_y)
{
    if(x==dest_x && y==dest_y) return true;
    if((x<0 || y<0 || x>n || y>m) || mat[x][y]==0 || visited[x][y]==true) return false;

    visited[x][y] = true;

    if(dfs(x+1, y, dest_x, dest_y) == true) return true;
    if(dfs(x, y+1, dest_x, dest_y) == true) return true;
    if(dfs(x-1, y, dest_x, dest_y) == true) return true;
    if(dfs(x, y-1, dest_x, dest_y) == true) return true;

    return false;
}
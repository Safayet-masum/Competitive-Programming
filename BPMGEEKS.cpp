#define NIL 0
#define INF INT_MAX
// A class to represent Bipartite graph for Hopcroft
// Karp implementation GEEKFORGEEKS
list<int>adj[200005];
int pairU[200005], pairV[200005], dist[200005];
class BipGraph
{
public:
    int m, n;
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};
int BipGraph::hopcroftKarp()
{
    int result = 0;
    while (bfs())
    {
        for (int u=1; u<=m; u++)
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}
bool BipGraph::bfs()
{
    queue<int> Q;
    for (int u=1; u<=m; u++)
    {
        if (pairU[u]==NIL)
        {
            dist[u] = 0;
            Q.push(u);
        }
        else
            dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL])
        {
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                int v = *i;
                if (dist[pairV[v]] == INF)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}
bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            int v = *i;
            if (dist[pairV[v]] == dist[u]+1)
            {
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    for(int i=0; i<=m; i++)
    {
        pairU[i]=0;
        adj[i].clear();
    }
    for(int i=0; i<=n; i++)
    {
        pairV[i]=0;
    }
}
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

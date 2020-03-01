#include<bits/stdc++.h>

using namespace std;

int s,g;
vector <int> ans;
int red=0;
int vis[10007];
vector <int> adj[10007];

void dfs(int u)
{
    vis[u]=1;
    ans.push_back(u);
    if(u==g)
    {
        red=1;
        return;
    }
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
        if(red==1)
            return;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int e;
    memset(vis,0,sizeof vis);
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Enter start node"<<endl;
    cin>>s;
    cout<<"Enter goal node"<<endl;
    cin>>g;
    dfs(s);
    for(int i=0;i<ans.size();i++)
    {
        if(i!=ans.size()-1)
        {
            cout<<ans[i]<<"->";
        }
        else
        {
            cout<<ans[i]<<endl;
        }
    }

}

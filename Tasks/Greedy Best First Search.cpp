#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int wt[n+7],vis[n+7],dis[n+7];
    vector <int> adj[n+7],ans;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    cout<<"Enter the heuristic values of the nodes chronologically"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter the number of edges"<<endl;
    int e;
    cin>>e;
    cout<<"Enter the edges"<<endl;
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s,goal[n+7],g;
    cout<<"Enter the start node"<<endl;
    cin>>s;
    cout<<"Enter the number of goal nodes"<<endl;
    cin>>g;
    cout<<"Enter the goal node(s)"<<endl;
    for(int i=1;i<=g;i++)
    {
        cin>>goal[i];
    }

    priority_queue < pair<int,int> , vector < pair<int,int> > , greater < pair<int,int> > > q;
    q.push({0,s});
    vis[s]=1;
    pair <int,int> tmp;
    int red=0;
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        int u=tmp.second;
        ans.push_back(u);
        for(int i=1;i<=g;i++)
        {
            if(goal[i]==u)
            {
                red=1;
                break;
            }
        }
        if(red==1)
            break;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push({wt[v],v});
            }
        }
    }
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
    return 0;
}

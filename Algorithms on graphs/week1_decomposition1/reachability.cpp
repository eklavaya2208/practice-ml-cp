#include <bits/stdc++.h>

using namespace std;

int explore(vector<vector<int>> &v,int visited[],int u,int w){
    if(visited[u]==1)
        return 1;
    if(visited[w]==1)
        return 0;
    visited[w]=1;
    for(auto i=v[w].begin();i<v[w].end();i++){
        explore(v,visited,u,*i);
    }
    
    if(visited[u]==1)
        return 1;
    else
        return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int u,w;
    int visited[n];
    memset(visited, 0, sizeof(visited));
    cin>>u>>w;
    cout<<explore(v,visited,u,w);
}

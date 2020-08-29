#include <bits/stdc++.h>

using namespace std;

int explore(int visited[],vector<vector<int>> &v,int u,int w){
    if(u==w)
        return 0;
    if(visited[u]==1)
        return 1;
    if(w==0)
        w=u;
    visited[u]=1;
    int a = 1;
    if(!v[u].empty()){
        for(auto i=v[u].begin();i<v[u].end();i++){
            a = a & explore(visited,v,*i,w);
        }
    }
    
    return a;
}

int checkCycle(vector<vector<int>> &v,int u,int n){
    int visited[n];
    memset(visited,0, sizeof(visited));
    return explore(visited,v,u,0);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(!checkCycle(v,i,n)){
            flag=1;
            break;
        }
    }
    cout<<flag;
}

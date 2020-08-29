#include <bits/stdc++.h>

using namespace std;

struct node{
    vector<int> nn;
    int dist = -1;
};

void bfs(queue<int> q,vector<node> &v,int w,int visited[]){
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(!v[a].nn.empty()){
//            cout<<a;
            for(auto i=v[a].nn.begin();i<v[a].nn.end();i++){
                int x=*i;
                if(visited[x]!=1){
//                    cout<<"ok"<<endl;
                    v[x].dist=v[a].dist+1;
                    visited[x]=1;
                    q.push(x);
                    if(x==w)
                        return;
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<node> v(n+1);
    for(int i=0;i<m;i++){
        int a,b,flag=0;
        cin>>a>>b;
        for(auto j=v[a].nn.begin();j<v[a].nn.end();j++){
            if(*j==b){
                flag=1;
                break;
            }
        }
        if(flag)
            continue;
        v[b].nn.push_back(a);
        v[a].nn.push_back(b);
    }
    int u,w;
    cin>>u>>w;
    /*for(int i=1;i<=n;i++){
        for(auto j=v[i].nn.begin();j<v[i].nn.end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    cout<<u<<" "<<w<<endl;*/
    queue<int> q;
    q.push(u);
//    cout<<q.front()<<endl;
    v[u].dist=0;
    int visited[n+1];
    memset(visited, 0, sizeof(visited));
    visited[u]=1;
    bfs(q,v,w,visited);
    cout<<v[w].dist;
}

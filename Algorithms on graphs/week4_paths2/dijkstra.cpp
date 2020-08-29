#include <bits/stdc++.h>

using namespace std;

struct node{
    vector<pair<int,int>> nn;
    int dist = INT_MAX;
    int index;
};

struct comparedist{
    bool operator()(node &n1,node &n2){
        return (n1.dist>n2.dist);
    }
};

void djikstra(priority_queue<node,vector<node>,comparedist> &pq,vector<node> &v,int w,int visited[]){
    while(!pq.empty()){
        node a = pq.top();
        if(a.index==w)
            return;
        pq.pop();
        if(visited[a.index]!=1){
            for(auto i=a.nn.begin();i<a.nn.end();i++){
                int j = i->second;
                if(v[j].dist>a.dist + i->first){
                    v[j].dist=a.dist + i->first;
                }
                pq.push(v[j]);
            }
            visited[a.index]=1;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<node> v(n+1);
    for(int i=1;i<=n;i++){
        v[i].index=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].nn.push_back(make_pair(c,b));
    }
    int u,w;
    cin>>u>>w;
    v[u].dist=0;
    priority_queue<node,vector<node>,comparedist> pq;
    pq.push(v[u]);
    int visited[n+1];
    memset(visited,0, sizeof(visited));
    djikstra(pq,v,w,visited);
    if(v[w].dist!=INT_MAX)
        cout<<v[w].dist;
    else
        cout<<-1;}

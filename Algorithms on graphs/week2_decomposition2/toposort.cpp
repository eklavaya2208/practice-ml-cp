#include <bits/stdc++.h>

using namespace std;

int clo=0;

struct node{
    vector<int> v;
    int order=-1;
    int index = 0;
};

bool compareord(node n1,node n2){
    return (n1.order>n2.order);
}

void explore(vector<node> &c,int visited[],int a){
    if(visited[a]==1)
        return;
    visited[a]=1;
    if(!c[a].v.empty()){
        for(auto i=c[a].v.begin();i<c[a].v.end();i++){
            explore(c,visited,*i);
        }
    }
    c[a].order = ++clo;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<node> a(n+1);
    for(int i=1;i<=n;i++){
        a[i].index=i;
    }
    for(int i=0;i<m;i++){
        int b,c;
        cin>>b>>c;
        a[b].v.push_back(c);
    }
    int visited[n+1]={0};
    for(int i=1;i<=n;i++){
        if(visited[i]!=1){
            explore(a,visited,i);
        }
    }
    sort(a.begin(),a.end(),compareord);
    for(int i=0;i<n;i++){
        cout<<a[i].index<<" ";
    }
}

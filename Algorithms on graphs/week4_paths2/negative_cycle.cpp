#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node{
    vector<pair<int,int>> nn;
    int dist= 10000;
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<node> v(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].nn.push_back(make_pair(b,c));
    }
    
    v[1].dist =0;
    for(int k=1;k<n;k++){
        for(int i=1;i<=n;i++){
            if(!v[i].nn.empty()){
                for(auto j=v[i].nn.begin();j<v[i].nn.end();j++){
                    int a,b;
                    a = j->first;
                    b = j->second;
                    if(v[i].dist+b<v[a].dist)
                        v[a].dist=v[i].dist+b;
                }
            }
        }
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(!v[i].nn.empty()){
            for(auto j=v[i].nn.begin();j<v[i].nn.end();j++){
                int a,b;
                a = j->first;
                b = j->second;
                if(v[i].dist+b<v[a].dist){
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    if(flag)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}



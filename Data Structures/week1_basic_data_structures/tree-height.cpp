#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > vec;
vector<int> h;
void height(int x){
    for(int i=0;i<vec[x].size();i++){
        h[vec[x][i]]=h[x]+1;
        height(vec[x][i]);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // vec is an adjacency list
    vec.resize(n);
    int root;
    for(int i=0;i<n;i++){
        if(v[i]==-1){
            root=i;
            continue;
        }
        vec[v[i]].push_back(i);
    }
    h.resize(n);
    h[root]=1;
    height(root);
    int ma=0;
    for(int i=0;i<h.size();i++){
        // cout<<i<<" -- "<<h[i]<<endl;
        ma=max(ma,h[i]);
    }
    cout<<ma<<endl;
}


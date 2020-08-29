#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct prenode{
    int key;
    int li;
    int ri;
};

void print_in(vector<prenode> &v,int k){
    if(v[k].li!=-1)
        print_in(v,v[k].li);
    printf("%d ",v[k].key);
    if(v[k].ri!=-1)
        print_in(v,v[k].ri);
}

void print_pr(vector<prenode> &v,int k){
    printf("%d ",v[k].key);
    if(v[k].li!=-1)
        print_pr(v,v[k].li);
    if(v[k].ri!=-1)
        print_pr(v,v[k].ri);
}

void print_po(vector<prenode> &v,int k){
    if(v[k].li!=-1)
        print_po(v,v[k].li);
    if(v[k].ri!=-1)
        print_po(v,v[k].ri);
    printf("%d ",v[k].key);
}

int main(){
    int n;
    cin>>n;
    vector<prenode> v(n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v[i].key,&v[i].li,&v[i].ri);
    }
    print_in(v,0);
    cout<<endl;
    print_pr(v,0);
    cout<<endl;
    print_po(v,0);
    cout<<endl;
}

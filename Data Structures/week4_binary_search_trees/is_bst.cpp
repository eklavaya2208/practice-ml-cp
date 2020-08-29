#include <bits/stdc++.h>
using namespace std;

struct prenode{
    int key;
    int li;
    int ri;
};

int BSTutil(vector<prenode> &v,int k,int min,int max){
   if(v[k].key<min || v[k].key>max)
       return 0;
    
    if(v[k].li==-1 && v[k].ri==-1)
        return 1;
    
    int a=1,b=1;
    if(v[k].li!=-1){
        a = BSTutil(v,v[k].li,min,v[k].key-1);
    }
    if(v[k].ri!=-1){
        b = BSTutil(v,v[k].ri,v[k].key+1,max);
    }
    return (a&b);
}

int isBST(vector<prenode> &v,int k){
    return BSTutil(v,k,INT_MIN,INT_MAX);
}

int main(){
    int n;
    cin>>n;
    vector<prenode> v(n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v[i].key,&v[i].li,&v[i].ri);
    }
    if(n>0){
        if(isBST(v,0)==1)
            cout<<"CORRECT"<<endl;
        else
            cout<<"INCORRECT"<<endl;
    }
    else
        cout<<"CORRECT"<<endl;
}


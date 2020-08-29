#include <iostream>
#include <vector>

using namespace std;

struct node{
    int val;
    vector<node *> x;
    int child=0;
};

int max(int x,int y){
    if(x<y)
        return y;
    
    return x;
}


node * maketree(int parent,vector<int> v){
    node *temp = (node *)malloc(sizeof(node));
    temp->val = parent;
    for(int i=0;i<v.size();i++){
        if(v[i]==parent){
            temp->x.push_back(maketree(i,v));
            temp->child++;
        }
    }
    return temp;
}

int height(node * root){
    if(root->child==0){
        return 0;
    }
    int max = INT_MIN;
    for(int i=0;i<root->child;i++){
        int a= 1 + height(root->x[i]);
        if(a>max)
            max=a;
    }
    return max;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ind=0;
    for(int i=0;i<n;i++){
        if(v[i]==-1){
            ind=i;
            break;
        }
    }
    node root;
    root.val = ind;
    for(int i=0;i<n;i++){
        if(v[i]){
            root.x.push_back(maketree(i,v));
            root.child++;
        }
    cout<<height(&root);
    }
}


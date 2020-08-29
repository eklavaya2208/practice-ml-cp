#include <bits/stdc++.h>

using namespace std;

int max(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}

int arr2[300][100001];

int goldDP(int arr[],int n,int w){
    if(n==1 && arr[0]<=w){
        return arr[0];
    }
    else if(n==1)
        return 0;
    
    if(arr2[n-1][w]==0){
        if(arr[n-1]<=w){
            arr2[n-1][w] = max(goldDP(arr,n-1,w),arr[n-1]+goldDP(arr,n-1,w-arr[n-1]));
        }
        else{
            arr2[n-1][w] = goldDP(arr,n-1,w);
        }
    }
    
    return arr2[n-1][w];
}

int main(){
    int w,n;
    cin>>w>>n;
    int arr[n];
    memset(arr2,0,sizeof(arr2));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<goldDP(arr,n,w);
}


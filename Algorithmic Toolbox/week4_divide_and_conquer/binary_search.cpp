#include <iostream>

using namespace std;

int BinSearch(int arr[],int low,int high,int k){
    int mid = low + (high-low)/2;
    if(high>=low){
        if(arr[mid]<k){
            return BinSearch(arr,mid+1,high,k);
        }
        else if(arr[mid]>k){
            return BinSearch(arr,low,mid-1,k);
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int n,k,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    while(x--){
        cin>>k;
        cout<<BinSearch(arr,0,n-1,k)<<" ";
    }
}

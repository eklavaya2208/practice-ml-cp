#include <iostream>

using namespace std;

int max(int x,int y){
    return x>y?x:y;
}

int max(int x,int y,int z){
    return max(max(x,y),z);
}

int partition(int arr[],int n,int sum1,int sum2,int sum3){
    if(n==0){
        if(sum1==sum2 && sum2==sum3)
            return 1;
        else
            return 0;
    }
    
    return max(partition(arr,n-1,sum1+arr[n-1],sum2,sum3),partition(arr,n-1,sum1,sum2+arr[n-1],sum3),partition(arr,n-1,sum1,sum2,sum3+arr[n-1]));
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum1=0,sum2=0,sum3=0;
    if(n>2)
        cout<<partition(arr,n,sum1,sum2,sum3);
    else
        cout<<0;
}

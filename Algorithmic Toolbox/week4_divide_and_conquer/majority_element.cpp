#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,count=1,ans = 0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i-1] == arr[i]){
            count++;
            if(count>n/2){
                ans = 1;
            }
        }
        else
            count = 1;
    }
    cout<<ans<<endl;
}

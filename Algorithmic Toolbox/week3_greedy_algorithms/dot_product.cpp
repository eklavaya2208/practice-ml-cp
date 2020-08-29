#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long int> x(n),y(n);
    long long int ans = 0;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    sort(x.begin(),x.end(),greater<long long int>());
    sort(y.begin(),y.end(),greater<long long int>());
    for(int i=0;i<n;i++){
        ans += x[i]*y[i];
    }
    cout<<ans;
}

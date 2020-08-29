#include <iostream>
#include <vector>

using namespace std;

inline int MinRefills(vector<int> x, int n, int L){
    int lr=0,cr=0,ans=0;
    while(cr<=n){
        lr = cr;
        while(cr<=n && x[cr+1]-x[lr]<=L){
            cr++;
        }
        if(cr==lr){
            return -1;
            }
        if(cr<=n){
            ans++;
            }
        }
    return ans;
}

int main(){
    int d,L,n,ans;
    cin>>d>>L>>n;
    vector<int> x(n+2);
    x[0] = 0;
    x[n+1] = d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    ans = MinRefills(x,n,L);
    cout<<ans;
}

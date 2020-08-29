#include <iostream>

using namespace std;

int main(){
    int n,ans;
    cin>>n;
    ans = n/10;
    n = n%10;
    ans = ans + n/5;
    n = n%5;
    ans = ans + n;
    cout<<ans;
}


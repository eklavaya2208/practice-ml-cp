#include <iostream>

using namespace std;

int main(){
    int n,x,y,z;
    cin>>n;
    x = 0;
    y = 1;
    for(long long int i=2;i<n+1;i++){
        z = (x%10 + y%10)%10;
        x = y;
        y = z;
    }
    cout<<z;
}



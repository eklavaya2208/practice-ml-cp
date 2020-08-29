#include <iostream>
#include <vector>

using namespace std;

inline int psiano(int m){
    vector<int> v;
    int i;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    for(i=3;;i++){
        if(v[i-1] == 1 && v[i-2] == 0){
            break;
        }
        v[i] = v[i-1]+v[i-2];
    }
    return i-2;
}

int main(){
    long long int n;
    int m,a;
    cin>>n>>m;
    a = n%psiano(m);
    cout<<a/m;
}

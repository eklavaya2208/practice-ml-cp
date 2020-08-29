#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int min(int a,int b,int c){
    if(a<b){
        if(c<a)
            return c;
        else
            return a;
    }
    else{
        if(c<b)
            return c;
        else
            return b;
    }
}

int moneyChange(int money){
    vector<int> arr(money+1);
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<arr.size();i++){
        int a  = arr[i-1];
        int b  = INT_MAX;
        int c  = INT_MAX;
        if(i-3>=0)
            b = arr[i-3];
        if(i-4>=0)
            c = arr[i-4];
        arr[i] = min(a,b,c)+1;
    }
    return arr[money];
}

int main(){
    int n;
    cin>>n;
    cout<<moneyChange(n);
}

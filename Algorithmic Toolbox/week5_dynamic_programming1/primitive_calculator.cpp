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

void Backtrack(vector<int> arr){
    vector<int> ans;
    ans.push_back((int)arr.size()-1);
    for(auto j=arr.size()-1;j!=1;){
        int a = arr[j-1];
        int b = INT_MAX;
        int c = INT_MAX;
        if(j%2==0)
            b = arr[j/2];
        if(j%3==0)
            c = arr[j/3];
        if(min(a,b,c)==a)
            j--;
        else if(min(a,b,c)==b)
            j=j/2;
        else
            j=j/3;
        ans.push_back((int)j);
    }
    for(auto j=ans.end()-1;j>=ans.begin();j--)
        cout<<*j<<" ";
}

void primitiveCalc(int n){
    vector<int> arr(n+1);
    arr[1] = 0;
    for(int i=2;i<arr.size();i++){
        int a  = arr[i-1];
        int b  = INT_MAX;
        int c  = INT_MAX;
        if(i%2==0)
            b = arr[i/2];
        if(i%3==0)
            c = arr[i/3];
        arr[i] = min(a,b,c)+1;
    }
    cout<<arr[n]<<endl;
    Backtrack(arr);
}

int main(){
    int n;
    cin>>n;
    primitiveCalc(n);
}

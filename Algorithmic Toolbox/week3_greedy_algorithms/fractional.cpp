#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

struct greedy{
    double weight,value;
};

bool compareGreedy(greedy g1,greedy g2){
    double a,b;
    a = g1.value/g1.weight;
    b = g2.value/g2.weight;
    return(b<a);
}

int main(){
    double n,w,i;
    cin>>n>>w;
    vector<greedy> arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].value;
        cin>>arr[i].weight;
    }
    sort(arr.begin(),arr.end(),compareGreedy);
    double ans = 0.000;
    i=0;
    while(w && arr[i].weight!=0){
        if(w==0){
            break;
        }
        if (w>=arr[i].weight){
            w -= arr[i].weight;
            ans += arr[i].value;
            i++;
        }
        else{
            ans += (arr[i].value/arr[i].weight) * w;
            w = 0;
        }
    }
    printf("%.9f",ans);
}


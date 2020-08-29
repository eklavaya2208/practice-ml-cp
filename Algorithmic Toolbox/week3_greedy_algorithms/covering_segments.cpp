#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

struct segment{
    int left;
    int right;
};

bool minseg(segment x,segment y){
    return x.right<y.right;
}

int main(){
    int n;
    cin>>n;
    vector<segment> x(n);
    vector<segment>::iterator it;
    for(int i=0;i<n;i++){
        cin>>x[i].left>>x[i].right;
    }
    sort(x.begin(),x.end(),minseg);
    vector<int> point;
    int ans=0;
    int j=0;
    while(j<n){
        point.push_back(x[j].right);
        ans++;
        int i;
        for(i=j;i<x.size();i++){
            if(x[i].left<=point[ans-1] and point[ans-1]<=x[i].right)
                continue;
            else
                break;

        }
        j=i;

    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<point[i]<<" ";
    }
    cout<<endl;
}

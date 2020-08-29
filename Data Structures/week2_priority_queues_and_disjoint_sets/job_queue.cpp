#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct thread{
    long long int th;
    long long int st=0;
    
    thread(long long int th, long long int st)
        :th(th),st(st)
    {
    }
};

struct comparethread{
    bool operator()(thread const& t1,thread const& t2){
            if(t1.st!=t2.st)
                return (t1.st>t2.st);
            else
                return (t1.th>t2.th);
    }
};

void showpq(priority_queue<thread,vector<thread>,comparethread> pq){
    while(!pq.empty()){
        cout<<pq.top().th<<" "<<pq.top().st<<" | ";
        pq.pop();
    }
    cout<<endl;
}


int main(){
    long long int n,m;
    cin>>n>>m;
    priority_queue<thread,vector<thread>,comparethread> pq;
    for(long long int i=0;i<n;i++){
        pq.push(thread(i,0));
    }
    //showpq(pq);
    long long int arr[m];
    for(long long int i=0;i<m;i++){
        cin>>arr[i];
    }
    vector<thread> ans;
    for(long long int i=0;i<m;i++){
        thread temp(0,0);
        temp = pq.top();
        pq.pop();
        ans.push_back(temp);
        temp.st+=arr[i];
        pq.push(temp);
        //showpq(pq);
    }
    for(auto i=ans.begin();i<ans.end();i++){
        cout<<i->th<<" "<<i->st<<endl;
    }
}





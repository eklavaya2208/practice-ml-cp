#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

typedef long long int ll;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll hashstr(string s,ll m){
    const ll x=263,p=1000000007;
    ll z = 0;
    for(ll i=0;i<s.length();i++){
        ll a = power(x,i,p);
        ll b = s.at(i);
        z += ((a*b)%p)%m;
        z=z%m;
    }
    z=z%m;
    return z;
}

int main(){
    ll m,n;
    cin>>m>>n;
    vector<list<string>> v(m);
    vector<string> str = {"add","del","find","check"};
    string str2,str3;
    for(int j=0;j<n;j++){
        cin>>str2;
        if(str2==str[0]){
            cin>>str3;
            ll x = hashstr(str3,m);
            int flag=0;
            if(!v[x].empty()){
                for(auto i = v[x].begin();i!=v[x].end();i++){
                    if(*i==str3){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                v[x].push_front(str3);
            }
        }
       else if(str2==str[1]){
            cin>>str3;
            ll x = hashstr(str3,m);
            if(!v[x].empty()){
                for(auto i = v[x].begin();i!=v[x].end();i++){
                    if(*i==str3){
                        v[x].erase(i);
                        break;
                    }
                }
            }
        }
        else if(str2==str[2]){
            cin>>str3;
            ll x = hashstr(str3,m);
            int flag=0;
            if(!v[x].empty())
            for(auto i = v[x].begin();i!=v[x].end();i++){
                if(*i==str3){
                    flag=1;
                    cout<<"yes"<<endl;
                    break;
                }
            }
            if(flag==0)
                cout<<"no"<<endl;
        }
        else if(str2==str[3]){
            int a;
            cin>>a;
            if(!v[a].empty())
            for(auto i = v[a].begin();i!=v[a].end();i++){
                cout<<*i<<" ";
            }
            cout<<endl;
        }
    }
}


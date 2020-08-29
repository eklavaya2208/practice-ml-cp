#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define iter(a, b, c) for(auto(a) = (b); (a) < (c); ++(a))

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pp;
typedef vector<pp> vpp;
typedef vector<ll> vll;
typedef vector<char> vc;

int fpower(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int minimum(int x,int y){
    if(x<y)
        return x;
    else return y;
}

int maximum(int x,int y){
    if(x>y)
        return x;
    else return y;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<"Hello"<<endl;
}

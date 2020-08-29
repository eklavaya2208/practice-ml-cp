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
    fstream f,x;
    f.open("test.txt",ios::out | ios::in);
    x.open("output.txt",ios::trunc| ios::out | ios::in);
    int t;
    f>>t;
    for(int i=1;i<=t;i++){
        x<<"Case #"<<i<<": ";
        int n;
        f>>n;
        string s;
        f>>s;
        int c0=0,c1=0;
        iter(j,0,n){
            if(s[j]=='A')
                c0++;
            else if(s[j]=='B')
                c1++;
        }
        int max = maximum(c0,c1);
        int min = minimum(c0,c1);
        if(max-1==min)
            x<<"Y"<<endl;
        else
            x<<"N"<<endl;
    }
    x.close();
    f.close();
}


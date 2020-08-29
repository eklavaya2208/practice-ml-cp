#include <iostream>
#include <string>

using std::string;

int min(int x,int y){
    if(x<y)
        return x;
    else
        return y;
}

int min(int x, int y , int z)
{
    return min(min(x, y), z);
}

int edit_distance(string str1,string str2) {
    int i,j;
    int len1 = (int)str1.length();
    int len2 = (int)str2.length();
    int dp[len1+1][len2+1];
    for(i=0;i<=len1;i++){
        for(j=0;j<=len2;j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
            }
        }
    return dp[len1][len2];
    }
  

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}



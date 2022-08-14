#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define WOW ios::sync_with_stdio(false);cin.tie(0);
#define PB push_back
#define F first
#define S second
#define INF 2147483647
#define LINF 4294967295
#define Mod 10e9+7
//#pragma GCC optimize("O3")

string s1,s2,s3;
int len1,len2,len3;
int dp[105][105][105];

bool check(int x,int y,int z){
    if(s1[x] == s2[y] && s2[y] == s3[z]) return true;
    else return false;
}

void LCS(){
    for(int i = 1 ; i <= len1; i++)
        for(int j = 1 ; j <= len2 ; j++)
            for(int k = 1 ; k <= len3 ; k++)
                if(check(i-1 , j-1 , k-1))
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
    cout << dp[len1][len2][len3];
}

int main(){
    WOW
    cin >> s1 >> s2 >> s3;
    len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    memset(dp,0,sizeof(dp));

    LCS();
}


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

int dp[45][3],n,a[45];

void debug(){
    for(int i = 0 ; i <= n; i++){
        for(int j = 0 ; j <= 2 ;j++)
            cout << dp[i][j] << " ";
    cout << "\n";
    }
}

int main(){
    WOW
    while(cin >> n){
        if(n == 0 ) break;
        for(int i = 1 ; i <= n ; i++)
            cin >> a[i];
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <=2 ; j++)
                dp[i][j] == 0;
        for(int i = 1 ; i <= n; i++)
            for(int j = 0 ; j <= 2 ;j++){
                if(j == 0 )
                    dp[i][j] = dp[i-1][2];
                else if(j == 1)
                    dp[i][j] = max(dp[i-1][1] + a[i], dp[i-1][0] + a[i]);
                else
                    dp[i][j] = max(dp[i-1][0] + 2*a[i], dp[i-1][1] + 2*a[i]);
            }
        int ans = dp[n][0];
        for(int i = 1 ; i <= 2 ; i++)
            if(ans < dp[n][i])
                ans = dp[n][i];
        cout << ans <<"\n";
    }
    return 0;
}

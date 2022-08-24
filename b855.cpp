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

int n,t,a[1005],sum,half;

int main(){
    WOW
    cin >> n;
    while(n--){
        sum = 0;
        cin >> t;
        for(int i = 0 ; i < t ; i++){
            cin >> a[i];
            sum += a[i];
        }
        ll half = sum/2;
        vector<ll> dp(half+1,0);
        for(int i = 0 ; i < t; i++)
            for(int j = half ; j >= a[i] ; j--)
                dp[j] = max(dp[j-a[i]] + a[i],dp[j]);
        cout << dp[half]*dp[half] + (sum-dp[half])*(sum-dp[half]) << "\n";
    }
    return 0;
}


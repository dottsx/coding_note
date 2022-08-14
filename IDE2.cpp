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

int dp[1005][205],n,tau,l;

struct Box{
    int w,v;
}box[205];

bool cmp(Box a, Box b){
    return a.w > b.w;
}

void f(){
    memset(dp,0, sizeof(dp));
    for(int i = 0 ; i < n;i++){
        int w = box[i].w, v = box[i].v;
        for(int j = tau; j >= w ; j-- ){
            int wk = 0;
            for(int k = 1 ; k <= l ;k++){
                wk += w;
                if(j - wk < 0) break;
                dp[j][k] = max(dp[j][k],dp[j-wk][k-1] + v);
            }
        }
    }
    int ans = 0;
    for(int i =0 ; i <= tau ; i++)
        for(int j = 0 ; j <= l ; j++)
            if(ans < dp[i][j]) ans = dp[i][j];
    cout << ans << "\n";
}

int main(){
    WOW
    cin >> n >> tau >> l;
    for(int i = 0 ; i < n; i++)
        cin >> box[i].w >> box[i].v;
    sort(box,box + n ,cmp);
    f();
    return 0;
}


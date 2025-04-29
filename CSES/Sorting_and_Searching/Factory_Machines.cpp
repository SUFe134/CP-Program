/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

//const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, t, arr[MAXN], mid, l, m, r;

bool check(int m){
    int count = 0;
    for(int i = 0; i < n; ++i){
        count += m / arr[i]; // m/arr[i]可做的產品個數
        if(count >= t) return true; //總和大於等於t, 表 m 可行

    }
    return false;
}
signed main(){
    opt;
    cin >> n >> t;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    r = 1e18; //最糟的情況：最大t = 1e9, n = 1, 一台機器要花 1e9製作一個， t個 = 1e9 * 1e9 = 1e18
    while(r - l > 1){
        m = (r + l) / 2;
        //cout << m << "\n";
        if(check(m)) r = m; // m秒可生產足夠產品，往左繼續找更短的時間
        else l = m; // m秒不夠，往右找更長的時間
        //cout << l << " " << r << "\n";
    }
    cout << r;
}
//對答案二分搜
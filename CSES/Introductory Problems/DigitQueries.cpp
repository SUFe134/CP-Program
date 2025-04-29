/* Question : OJ Number */

#include <bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
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

// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

ll q, k, p[20], pref[20];
ll ind, ans, x, y;

void initialize()
{
    // 建表p[i]，代表幾位數，範圍到10^19
    p[0] = 1;
    for (int i = 1; i < 19; ++i)
    {
        p[i] = p[i - 1] * 10;
    }
    // pref[i]儲存各位數之間的數量總和
    pref[1] = 9;
    for (int i = 2; i < 18; ++i)
    {
        pref[i] = p[i - 1] * 9 * i; // i 表當下有幾位
    }
}

void slove()
{
    ind = 1;
    while (k > pref[ind])
    {
        k -= pref[ind++]; // 第index位數的第k個字元
        // cout << pref[ind++] << " ";
    }
    k--;         // 轉成 0-index（從 1-based 變成 0-based）
    x = k / ind; // x 是第幾個數字（從0開始算）
    y = k % ind; // y 是這個數字中的第幾個位數
    //cout << ind << "/" << k << "/" << x << "/" << y << "\n";
    ans = p[ind - 1] + x;
    string s = to_string(ans);
    cout << s[y] << "\n";
}

signed main()
{
    opt;
    initialize();
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> k;
        slove();
    }
}
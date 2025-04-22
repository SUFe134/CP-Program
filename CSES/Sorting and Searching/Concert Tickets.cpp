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
#define all(v) v.begin(), v.end()
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

int n, m, x;
multiset<int> h;
signed main()
{
    opt;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        auto it = h.upper_bound(x);
        if (it == h.begin()) cout << -1 << "\n";
        else
        {
            cout << *(--it) << "\n";
            h.erase(it);  // 確保該元素不再被重複使用
        }
    }

    return 0;
}
// 【用途】針對「已經排序」的資料進行binary search。
//         vector <int> v;
//         sort(v.begin(), v.end());
// lower_bound：找出vector中「大於或等於」val的「最小值」的位置：
//         auto it = lower_bound(v.begin(), v.end(), val);
// upper_bound：找出vector中「大於」val的「最小值」的位置：
//         auto it = upper_bound(v.begin(), v.end(), val);

// 與 set 用法雷同，但會保留重複的元素，資料由小到大排序。
// 宣告：
// multiset<int> st;
// 刪除資料：
// st.erase(val); 會刪除所有值為 val 的元素。
// st.erase(st.find(val)); 只刪除第一個值為 val 的元素。

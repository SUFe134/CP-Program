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

// const auto dir = vector<pair<int, int > > {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

string s, half;
int oddCount = 0, oddIndex = -1;
signed main()
{
    opt;
    int count[26] = {};
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        count[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (count[i] % 2 == 1)
        {
            oddCount++;
            oddIndex = i;
        }
    }
    if (oddCount > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (count[i] % 2 == 0) half += string(count[i] / 2, 'A' + i);
    }
    string ans = half;
    if (oddIndex != -1) ans += string(count[oddIndex], 'A' + oddIndex);
    reverse(half.begin(), half.end());
    ans += half;
    cout << ans;
}

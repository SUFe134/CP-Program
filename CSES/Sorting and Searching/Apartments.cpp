/* Question : OJ Number */

#include <bits/stdc++.h>
using namespace std;

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

int n, m, k, ap = 0, bp = 0, ans = 0, x;
vector<int> a;
vector<int> b;


signed main()
{
    opt;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i){
        cin >> x;
        a.pb(x);
    }
    for (int i = 0; i < m; ++i){
        cin >> x;
        b.pb(x);
    }

    vsort(a);
    vsort(b);

    while(ap < n && bp < m){
        if(abs(a[ap] - b[bp]) <= k){
            ap++;
            bp++;
            ans++;
        }
        else if(b[bp] > a[ap] + k) ap++; //公寓 > 可接受範圍，換下一個人
        else if(b[bp] < a[ap] - k) bp++; //公寓 < 可接受範圍，換下一間房


    }
    cout << ans << "\n";
}
//雙指標
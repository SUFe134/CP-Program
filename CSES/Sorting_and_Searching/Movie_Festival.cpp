#include<bits/stdc++.h>
using namespace std;

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, x, y;
vector<pii> v;

signed main(){
    opt;
    cin >> n;
    for(int i = 0; i < n; ++i){
      cin >> x >> y;
      v.pb({y, x}); // 先記錄結束時間，然後記錄開始時間

    }
    int ans = 0, last = 0; //記錄上一部電影的結束時間
    sort(v.begin(), v.end()); //用結束時間做排序
    for(auto [end, start] : v){
      if(start >= last){ //如果這部電影的開始時間 >= 上一部電影的結束時間
        ans++;
        last = end;
      }
    }
    cout << ans;
}
//貪心
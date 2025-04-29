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

int x, n;
vector<int> v;
map<int, int> m;

signed main(){
    opt;
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        v.pb(a);
    }
    for(int i = 0; i < n; ++i){
        if(m.count(x - v[i])){
            //m.count(): map 不允許重複的鍵，所以此函數的返回值只能是 0 或 1。
            //時間複雜度：O(log n)
            cout << i + 1 << " " << m[x - v[i]] << "\n";
            // m[x - v[i]]是這個數字的位置，即是value
            return 0;
        }
        m[v[i]] = i + 1;
    }
    cout << "IMPOSSIBLE";


}
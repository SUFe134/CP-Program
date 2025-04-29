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
const int MAXN = 2e5 + 5;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, arr[MAXN], max_sum = -1e9, cur = 0;

signed main(){
    opt;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i){
        //cout << arr[i] << " " << arr[i] + cur << "\n";
        cur = max(arr[i], arr[i] + cur);
        //cout << "cur " << cur << "\n";
        //cout << "max_sum " << max_sum << "\n";
        max_sum = max(max_sum, cur);
        //cout << "max_sum " << max_sum << "\n";
    }
    cout << max_sum;
}
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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, arr[MAXN], pos[MAXN], ans = 1, a, b;
set<int>s;


signed main(){
    opt;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int round = 1;
    for(int i = 2; i <= n; ++i) if(pos[i - 1] > pos[i]) round++;

    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        --a, --b;
        for(int i = -1; i <= 1; ++i){
            int va = arr[a] + i;
            int vb = arr[b] + i;
            if(1 <= va && va <= n) s.insert(va);
            if(1 <= vb && vb <= n) s.insert(vb);
        }
        for(int val : s){
            if(val >= 2 && pos[val - 1] > pos[val]) round--;
        }
        swap(arr[a], arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;

        for(int val : s){
            if(val >= 2 && pos[val - 1] > pos[val]) round++;
        }
        cout << round << "\n";
    }

}
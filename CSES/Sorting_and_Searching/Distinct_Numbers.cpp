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
const int MAXN = 1e9 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;


int n, ans = 1, x;

//vector
/*
vector<int> v;
signed main(){
    opt;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v.pb(x);
    }
    vsort(v);
    for(int i = 1; i < n; ++i){
        if(v[i] != v[i - 1]) ans++;
    }
    cout << ans << "\n";
}
*/

//set
//set 裡面的元素是唯一的，具有不重複的特性，而且是有排序(小到大排)的容器，set 裡面元素的值是不可修改，但 set 可以插入或刪除元素
set<int> s;
signed main(){
    opt;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}
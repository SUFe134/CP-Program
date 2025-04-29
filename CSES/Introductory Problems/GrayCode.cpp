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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, total, gray;
string s;
signed main(){
    opt;
    cin >> n;
    total = 1 << n; // 2^n
    for(int i = 0; i < total; ++i){
        gray = i ^ (i >> 1); // i 和 i >> 1 （把i右移一位後的結果）做xor
        // why use xor: 同為 0 或同為 1 → 得 0，不同 → 得 1
        s = bitset<16>(gray).to_string().substr(16 - n);
        //bitset<16> 表示：我們要用 16 位元 來表示這個數字。
        //substr(16 - n) 只取 16-n 之後的
        cout << s  << "\n";
    }
}
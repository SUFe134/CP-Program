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

int n, a, b;
int mod_pow(int a, int b){
    int temp = 1;
    while(b > 0){
        if(b & 1) temp = temp * a % Mod; //if b 的最右邊是1
        a = a * a % Mod; //把a平方
        b >>= 1; //右移一位，等於整數除以2 ~（b = b / 2）
    }
    return temp;

}

signed main(){
    opt;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        cout << mod_pow(a, b) << "\n";
    }
}
// 快速冪 :根據 b 的二進位 來判斷是否乘上某個次方的 a
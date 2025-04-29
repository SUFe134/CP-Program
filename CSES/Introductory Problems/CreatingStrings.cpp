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

string n;
vector<string> v;
signed main(){
    opt;
    cin >> n;
    sort(n.begin(), n.end());
    do{
        v.push_back(n);
    }while(next_permutation(n.begin(), n.end()));
    //next_permutation(first, last) -> 會得到下一個範圍內的排列組合，沒有下一個排列組合就會回傳false,否則回傳true
    //is_permutation：判斷陣列 b 是否為陣列 a 排序後的結果。
        //is_permutation(a, a+5, b);
    //next_permutation：使用已經排序(由小到大)的資料，產生下一組排列。
    //prev_permutation：針對已經「逆向」排序(由大到小)的資料，產生上一組排序。
    cout << v.size() << "\n";
    for(auto i : v) cout << i << "\n";
}
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
const int MAXN = 1e9 + 10;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, k, arr[200005];
multiset<int> l, r;

void balance(multiset<int> &l, multiset<int> &r){
    // while(l.size() > r.size()){
    //     r.insert(*l.rbegin());
    //     l.erase(l.rbegin());
    // }
    // while(r.size() > l.size()){
    //     l.insert(*r.begin());
    //     r.erase(r.begin());
    // }
    while (l.size() > r.size()) {
        // l比r多2個以上，要平衡
        auto it = l.rbegin(); //l.rbegin() 是 reverse_iterator
        r.insert(*it);
        l.erase(prev(it.base())); // 刪掉最大值
        //erase() 只能接受 iterator 或 value
        //rbegin()不能直接 erase(), 要 .base() 再 prev()
    }
    while (l.size() < r.size()) {
        // r比l多，要平衡
        auto it = r.begin();
        l.insert(*it);
        r.erase(it);
    }

}

signed main(){
    opt;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i){
        if(!l.size() || arr[i] <= *l.rbegin()){
            l.insert(arr[i]);
            //cout << *l.rbegin() << "\n";
        }
        //l.size() -> 空的回傳false
        //*l.rbegin() -> 取出最大的數(multiset預設是從小到大排列)
        else{
            r.insert(arr[i]);
            //cout << *r.begin() << "\n";
        }

        //滑出舊元素
        if( i >= k){
            int old = arr[i - k];
            //要被移除的舊元素 <= l的最大值，從left移除，否則從right移除
            if(l.size() && old <= *l.rbegin()) l.erase(l.find(old));
            else r.erase(r.find(old));
        }
        balance(l, r);
        if(i >= k - 1) cout << *l.rbegin() << ' ';

    }
    cout << "\n";

}
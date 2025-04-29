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

//const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 10;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, k, arr[MAXN];
int ans = 0, sum = 0, cnt = 1;

bool isValid(int arr[], int n, int k, int mid){
    //判斷是否能分成k組
    cnt = 1; //至少有一組子陣列
    sum = 0; //當前組的總和
    for(int i = 0; i < n; ++i){
        if(sum + arr[i] > mid){
            cnt++; //子陣列再加一，等同切一刀
            sum = arr[i]; //當前的總和從最後加上去的那個數開始算
            // cout << "cnt " << cnt << " sum " << sum << "\n";
        }
        else sum += arr[i];
    }
    // if(cnt <= k) return true;
    // else return false;
    return cnt <= k; //如果子陣列數量小於等於k回傳true
}

int slove(int arr[], int n, int k){
    //二分搜範圍 最小是陣列中最大的數，最大是陣列中所有數的總和
    int l = *max_element(arr, arr + n), h = 0;
    for(int i = 0; i < n; ++i) h += arr[i]; //最大可能： 總和
    ans = h;
    while(l <= h){
        int mid = (l + h) / 2;
        // cout << l << " " << h << "\n";
        // cout << "mid: " << mid << "\n";
        if(isValid(arr, n, k, mid)){
            ans = mid;
            h = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

signed main(){
    opt;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << slove(arr, n, k) << "\n";
}
//二分搜 貪心
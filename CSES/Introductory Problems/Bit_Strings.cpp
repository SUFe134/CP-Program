#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long n, ans;
int main()
{
    cin >> n;
    ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans * 2) % MOD;
    }
    cout << ans << "\n";
}
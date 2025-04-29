#include <bits/stdc++.h>
using namespace std;
long long n, ans;

int main()
{
    int count = 0;
    cin >> n;
    ans = 1;
    for (int i = 5; i <= n; i *= 5)
    {
        count += n / i;
    }

    cout << count;
}
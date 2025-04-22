#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int main()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b;
        if ((a + b) % 3 != 0 || (a / 2) > b || (b / 2) > a)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
}
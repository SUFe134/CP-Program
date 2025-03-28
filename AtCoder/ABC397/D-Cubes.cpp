#include<bits/stdc++.h>
using namespace std;

#define int long long

int  N, x, y;
bool flag = false;

bool valid(int d, int y){
    return 3 * y * y + 3 * d * y + d * d > N / d;
}

signed main(){
    cin >> N;
    // O(3√n)
    for( int i = 1 ; i * i * i <= N ; ++i ){ // i equal d equal x - yn
        int res = 1, step = 1e9;

        while( step > 0 ){
            // O(log N)
            if( valid(i, res + step) ) step /= 2;
            else res += step;
        }

        if( (i + res) * (i + res) * (i + res) - res * res * res == N ){
            cout << res + i << " " << res << "\n";
            flag = true;
            break;
        }
    }

    if(!flag) cout << "-1\n";
}
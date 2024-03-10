#include <bits/stdc++.h>

using namespace std;

const int N = 22, MAX = 1 << N;

int n, a[MAX], f[MAX];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < (MAX); i++) f[i] = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        f[a[i]] = a[i];
    }
    
    for(int i = 0; i < N; i++){
        for(int m = 0; m < MAX; m++){
            if(m & (1 << i))
                f[m] = max(f[m], f[m ^ (1 << i)]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << f[(MAX - 1) ^ a[i]] << " ";
    }
    return 0;
}
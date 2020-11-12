#include <bits/stdc++.h>

using namespace std;

#define ld long double
const int N = 1e6+5;
const ld EPS = 1e-9;

int n,p,resp,up;
ld ans_max;

ld calc(int k){
    ld ans = p;
    ld ld_k = k, ld_n = n, ld_p = p;
    for(int i=0;i<p-1;i++){
        ans*=((ld_n-i)/(n+k-i));
    }
    ans*=(ld_k/(n+k-p+1));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    ld init = calc(1);
    ans_max = init;
    for(int i=1;i<=N;i++){
        ld aux = calc(i);
        if(aux > ans_max or abs(aux - ans_max) < EPS) ans_max = aux;
        else break;
    }
    cout << fixed << setprecision(10) << ans_max << "\n";
    return 0;
}
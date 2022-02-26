#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,m,kmin,kmax;
    cin >> n >> m;
    long long pair_max = n-m+1, teto = (n+m-1)/m, mult1,mult2;
    if(n%m) mult1 = n%m, mult2 = m-mult1;
    else mult1 = m, mult2 = 0;
    kmax = ((pair_max)*(pair_max-1))/2;
    kmin = (((teto)*(teto - 1))/2)*mult1;
    kmin += (((n/m)*(n/m - 1))/2)*mult2;
    cout << kmin << " " << kmax << "\n";
    return 0;
}
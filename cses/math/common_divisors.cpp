#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int d[N], x[N], cmp[N], ans;
vector<int> primes;

void sieve(){
    for(int i = 2; i < N; i++)
        if(!cmp[i]){
            for(int j = i * i; j < N; j += i) cmp[j] = 1;
            primes.push_back(i);
        }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
        int cnt = 0;
        for(int j = 0; j < primes.size() and primes[j] * primes[j] <= x[i]; j++){
            if(!(x[i] % primes[j])){
                d[primes[j]]++;
                if(d[primes[j]] >= 2) ans = max(primes[j], ans);
                if((x[i] / j) != j){
                    d[x[i]/j]++;
                    if(d[x[i]/j] >= 2) ans = max(ans, x[i]/j);
                }
                cnt++;
            }
        }
        d[x[i]]++;
        if(d[x[i]] >= 2) ans = max(x[i], ans);
    }
    printf("%d\n", ans);
    return 0;
}
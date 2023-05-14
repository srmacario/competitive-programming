#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 4;
const int N = 1e5 + 5;

ll v[N];
int k;
stack<int> s;

int main(){
    scanf("%d", &k);
    v[M] = 1;
    int n;
    for(n = M + 1; v[n - 1] < k; n++)
        v[n] = v[n - 1] * n / (n - M);
    while(k){
        int ub = upper_bound(v, v + n, k) - v;
        s.push(ub - 1);
        k -= v[ub - 1];
    }
    int sum = 0;
    while(!s.empty()){
        for(int i = 0; i < s.top() - sum; i++)
            printf("1");
        printf("0");
        sum = s.top();
        s.pop();
    }
    printf("\n");
    for(int i = 0; i < M; i++)
        printf("1");
    printf("0\n");
    return 0;
}
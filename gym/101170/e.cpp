#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 40;

pii a[N];
int n, s;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].st);
        a[i].nd = i;
        s += a[i].st;
    }
    sort(a, a + n);
    if(2 * a[n - 1].st > s)
        printf("impossible\n");
    else{
        for(int i = n - 1; i; i--)
            printf("%d ", a[i].nd + 1);
        printf("%d\n", a[0].nd + 1);
    }
    return 0;
}
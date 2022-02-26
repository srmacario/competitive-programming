#include <bits/stdc++.h>

using namespace std;

int v[100];

int main(){
    int n,m;
    cin  >> n >> m;
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    //perceba que fi <= 1000 então ans = 5000 garante que vou tirar o minimo da comparação
    int ans = 5000;
    sort(v,v+m);
    for(int i=0;i<m-n+1;i++){
        for(int j=i+n-1;j<m;j++){
            ans = min(ans,v[j]-v[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
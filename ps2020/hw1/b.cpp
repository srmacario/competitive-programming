#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n,q,v[N];

int lower(int k){
    int l=0, r = n-1;
    while(l < r){
        int m = (l+r)/2;
        if(v[m] < k) l = m+1;
        else r = m;
    }
    return (v[l] == k ? l : -1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<q;i++){
        int pos;
        cin >> pos;
        cout << lower(pos) << "\n";
    }
    return 0;
}
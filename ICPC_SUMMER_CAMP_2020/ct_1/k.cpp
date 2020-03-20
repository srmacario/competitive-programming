#include <bits/stdc++.h>

#define ll long long
#define pb push_back
const int N = 1e4+5;

using namespace std;

string s;
ll p[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    vector <ll> r;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1])
        r.pb((2*i+1));
    }
    ll k = 1;
    if(s[s.size()-1] == 'A') k = -1;
    if(!r.size()){
        cout << "0\n" << k << "\n";
        return 0;
    }
    p[0] = -r[0]*k;
    p[1] = 1*k;
    ll aux, ant;
    for(int i=1;i<r.size();i++){
        ll aux = p[0];
        for(int j=0;j<N;j++){
            aux = p[j];
            p[j] = -r[i]*p[j];
            if(j) p[j]+=ant;
            ant = aux;
        }
    }
    cout << r.size() << "\n";
    for(int i=r.size();i>=0;i--){
        cout << p[i];
        if(i) cout << " ";
    }
    cout << "\n";
    return 0;
}
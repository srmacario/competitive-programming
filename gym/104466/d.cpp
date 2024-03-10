#include <bits/stdc++.h>

using namespace std;

#define nd second;

typedef long double ll;
typedef pair<ll, ll> pll;

int v[5] = {4, 6, 8, 12, 20};
int d[5];
vector<ll> p[5];

vector<ll> mult(vector<ll> a, vector<ll> b){
    vector<ll> ans(a.size() + b.size() + 5);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            ans[i + j] += a[i] * b[j];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> cur = {1};
    for(int i = 0; i < 5; i++){
        cin >> d[i];
        p[i] = vector<ll>(v[i] + 1, 1);
        p[i][0] = 0;
        vector<ll> tmp = {1};
        for(int j = 0; j < d[i]; j++) tmp = mult(tmp, p[i]);
        cur = mult(cur, tmp);
    }
    vector<pll> ans;
    for(int i = 1; i < cur.size(); i++){
        if(cur[i]) ans.push_back({cur[i], i});
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a.second << " ";
    return 0;
}
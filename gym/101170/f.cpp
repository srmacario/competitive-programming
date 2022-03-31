#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 1e6 + 5;

int a, n;
set<pii> s[2];

bool inter(int l, int x, int y){
    auto lb = s[l].lower_bound({x, y});
    if(lb != s[l].end()){
        if(lb->st < y)
            return true;
    }
    if(lb != s[l].begin()){
        lb--;
        if(lb->nd > x)
            return true;
    }
    s[l].insert({x, y});
    return false;
}

int main(){
    map<int, vector<pii>> mp;
    scanf("%d", &n);
    for(int j = 0; j < 2; j ++)
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            mp[a].push_back({j, i});
        }
    auto i = mp.end();
    int ans = 0;
    while(i != mp.begin()){
        i--;
        vector<pii> h = i->nd;
        if(h[0].st != h[1].st){
            ans = i->st;
            break;
        }
        if(inter(h[0].st, h[0].nd, h[1].nd)){
            ans = i->st;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
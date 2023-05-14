#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

int n, x, y;
char c;
vector<pii> p, t, vn, vt, vp;

bool imp(){
    if(vn.empty()){
        vt = t;
        return false;
    }
    int ma = vn[0].nd, i = 0, j = 0;
    while(j < p.size() && p[j].st < vn[0].st)
        j++;
    while(j < p.size()){
        while(i + 1 < vn.size() && vn[i + 1].st <= p[j].st){
            i++;
            ma = max(ma, vn[i].nd);
        }
        if(p[j].nd <= ma)
            return true;
        j++;
    }
    ma = vn[0].nd, i = 0, j = 0;
    while(j < t.size() && t[j].st < vn[0].st){
        vt.push_back(t[j]);
        j++;
    }
    while(j < t.size()){
        while(i + 1 < vn.size() && vn[i + 1].st <= t[j].st){
            i++;
            ma = max(ma, vn[i].nd);
        }
        if(t[j].nd > ma)
            vt.push_back(t[j]);
        j++;
    }
    return false;
}

void elimp(){
    if(p.empty())
        return;
    vp.push_back(p[0]);
    int ma = p[0].nd;
    for(int i = 1; i < p.size(); i++){
        if(p[i].st == vp.back().st)
            vp.back().nd = p[i].nd;
        else if(p[i].nd > ma)
            vp.push_back(p[i]);
        ma = max(ma, p[i].nd);
    }
}

int fixpt(){
    int r = 0, j = (int)vt.size() - 1;
    for(int i = (int)vp.size() - 1; i >= 0; i--){
        r++;
        int mi = 1e9;
        while(j >= 0 && vt[j].st >= vp[i].st){
            if(vt[j].nd <= vp[i].nd)
                mi = min(mi, vt[j].nd);
            j--;
        }
        while(i > 0 && vp[i - 1].nd >= mi)
            i--;
    }
    return r;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %c", &x, &y, &c);
        if(c == 'P')
            p.push_back({2 * x - (1e8 - y), 2 * x + (1e8 - y)});
        else if(c == '-')
            t.push_back({2 * x - (1e8 - y), 2 * x + (1e8 - y)});
        else
            vn.push_back({2 * x - (1e8 - y), 2 * x + (1e8 - y)});
    }
    sort(p.begin(), p.end());
    sort(t.begin(), t.end());
    sort(vn.begin(), vn.end());
    if(imp())
        printf("impossible\n");
    else{
        elimp();
        printf("%d\n", fixpt());
    }
}
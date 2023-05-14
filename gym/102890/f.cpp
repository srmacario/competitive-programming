#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

set<pii> s[15];

int main(){
    s[1].insert({1, 1});
    for(int i = 2; i <= 14; i++){
        for(pii j : s[i - 1]){
            pii h = j;
            h.st += i;
            h.nd = max(i, h.nd);
            if(h.nd < h.st)
                swap(h.st, h.nd);
            s[i].insert(h);
            h = j;
            h.nd += i;
            h.st = max(i, h.st);
            if(h.nd < h.st)
                swap(h.st, h.nd);
            s[i].insert(h);
        }
        int last = 1e5;
        vector<pii> v;
        for(pii j : s[i]){
            if(j.nd >= last)
                v.push_back(j);
            else
                last = j.nd;
        }
        for(pii j : v)
            s[i].erase(j);
    }
    int w, h, ans = 0;
    scanf("%d %d", &w, &h);
    for(int i = 1; i < 14; i++)
        for(pii j : s[i])
            if((w >= j.st && h >= j.nd) || (w >= j.nd && h >= j.st))
                ans = i;
    printf("%d\n", ans);
    return 0;
}
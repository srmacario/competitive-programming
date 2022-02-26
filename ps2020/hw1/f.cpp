#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1e5+5;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<pair<ll,ll>> points;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            ll x,y;
            scanf("%lld %lld", &x, &y);
            points.push_back({x,y});
        }
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<n;i++){
            printf("%lld %lld\n", points[i].first, points[i].second);
        }
    }
    return 0;
}
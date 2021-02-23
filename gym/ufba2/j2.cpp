#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=2e5+5;

int n,m,s,c,resp;
map<int,int> mp;
set<int> cc;

int main(){
    scanf("%d %d %d", &n, &m, &s);
    mp[n-m+2]=0;
    for(int i=0;i<m;i++){
        scanf("%d", &c);
        cc.insert(c);
    }
    for(auto v:cc){
        mp[max(v-m+1,1)]++;
        mp[min(v+1,n-m+2)]--;
    }
    for(auto v=mp.begin();v!=mp.end();v++){
        s+=(*v).second;
        //cout<<(*v).first<<" "<<(*v).second<<" "<<s<<endl;
        if(s>=m){
            auto lb=v;
            lb++;
            resp+=(*lb).first-(*v).first;
        }
    }
    printf("%d\n", resp);
    return 0;
}
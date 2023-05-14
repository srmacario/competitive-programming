#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int t, ss[N][10], q[10], sf;
vector<int> v[10];
char s[N];

int main(){
    scanf(" %s", s);
    t = strlen(s);
    for(int i = t - 1; i >= 0; i--){
        for(int j = 0; j < 9; j++)
            ss[i][j] = ss[i + 1][j];
        ss[i][s[i] - '1']++;
    }
    for(int i = 0; i < t; i++)
        v[s[i] - '1'].push_back(i);
    for(int i = 0; i < 9; i++){
        scanf("%d", &q[i]);
        q[i] = v[i].size() - q[i];
        sf += q[i];
    }
    int l = 0;
    while(sf--){
        for(int i = 8; i >= 0; i--){
            if(!q[i])
                continue;
            auto lb = lower_bound(v[i].begin(), v[i].end(), l);
            if(lb != v[i].end()){
                bool ok = true;
                for(int j = 0; j < 9; j++)
                    if(ss[*lb][j] < q[j])
                        ok = false;
                if(ok){
                    printf("%d", i + 1);
                    q[i]--;
                    l = *lb + 1;
                    break;
                }
            }
        }
    }
    printf("\n");
    return 0;
}
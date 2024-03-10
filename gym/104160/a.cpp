#include <bits/stdc++.h>

using namespace std;

#define l first
#define r second

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

vector<pii> inter[2];
vector<pair<pii, int>> events;
ll sum[2][N], totsum[2][N], rsum[2][N];
ld ps_pond[2][N];
int n[2], unit[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n[0] >> n[1];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n[i]; j++){
            pii cur;
            cin >> cur.l >> cur.r;
            events.push_back({{cur.l, 0}, {i}});
            events.push_back({{cur.r, 1}, {i}});
        }
    }
    sort(events.begin(), events.end());
    int cur_l[2] = {-INF, -INF};
    for(auto e : events){
        //open
        if(e.first.second == 0){
            cur_l[e.second] = e.first.first;
            if(cur_l[e.second ^ 1] != -INF and cur_l[e.second ^ 1] != cur_l[e.second]){
                inter[e.second ^ 1].push_back({cur_l[e.second ^ 1], e.first.first});
                cur_l[e.second ^ 1] = e.first.first;
            }
        }
        //close
        else{
            if(cur_l[e.second] > e.first.first){
                cur_l[e.second] = -INF;
                continue;
            }
            inter[e.second].push_back({cur_l[e.second], e.first.first});
            cur_l[e.second] = -INF;
            if(cur_l[e.second ^ 1] != -INF){
                inter[e.second ^ 1].push_back({cur_l[e.second ^ 1], e.first.first});
                cur_l[e.second ^ 1] = e.first.first;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        inter[i].resize(unique(inter[i].begin(), inter[i].end()) - inter[i].begin());
        for(auto j = 0; j < inter[i].size(); j++){
            ps_pond[i][j + 1] = ps_pond[i][j] + ((inter[i][j].r + inter[i][j].l) / ((ld)2)) * (inter[i][j].r - inter[i][j].l);
            sum[i][j + 1] = sum[i][j] + (inter[i][j].r - inter[i][j].l);
            totsum[i][j + 1] = totsum[i][j + 1] + (inter[i][j].r);
            if(inter[i][j].l == inter[i][j].r) unit[i]++;
        }
        // cout << "\n";
    }
    ld ans = 0;
    //0 > 1
    for(int k = 0; k < 2; k++){
        for(int i = 0, j = 0; i < inter[k].size(); i++){
            while(j < inter[k^1].size() and inter[k^1][j].r <= inter[k][i].l){
                j++;
            }
            // cout << "j: " << j << "\n";
            if(j){
                ld VmB, pB, VmA, pA;
                if(sum[k][inter[k].size()]){
                    VmA = (inter[k][i].l + inter[k][i].r) / ((ld)2);
                    pA = ((ld)(inter[k][i].r - inter[k][i].l) / sum[k][inter[k].size()]);
                }
                else{
                    VmA = totsum[k][i + 1] / ((ld)(i + 1));
                    pA = (i + 1) / ((ld)n[k]);
                }

                if(sum[k^1][inter[k^1].size()]){
                    VmB = ps_pond[k^1][j] / sum[k^1][j];
                    pB = (sum[k^1][j]) / ((ld)sum[k^1][inter[k^1].size()]);
                }
                else{
                    //cout << totsum[k^1][j] << " " << j << " " << n[k^1] << "\n";
                    VmB = totsum[k^1][j] / ((ld) j);
                    pB = (j) / ((ld) n[k^1]);
                }
                // cout << VmA << " " << VmB << " " << pA << " " << pB << "\n";
                ans += (VmA - VmB) * pA * pB;
            }
            if(j < inter[k^1].size() and inter[k][i].l == inter[k^1][j].l and inter[k][i].l != inter[k][i].r){
                ld R = inter[k][i].r, L = inter[k][i].l;
                ans += ((R * R * R)/3 - (R * R * L) + (R * L * L) - (L * L * L) / 3) / (2 * sum[1][inter[1].size()] * sum[0][inter[0].size()]);
            }
            // cout << setprecision(15) << fixed << ans << "\n";

        }
    }
    cout << setprecision(15) << fixed << ans << "\n";
}
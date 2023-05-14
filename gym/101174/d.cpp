#include <bits/stdc++.h>
using namespace std;


#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
typedef long double ld;

int n, d, c, x;
ld esc[60][60], dp[20][20][20];
bool vis[20][20][20];

ld calc(int s1, int s2, int s12){
    if(s1 + s12 == 0 || s2 + s12 == 0)
        return 0;
    if(vis[s1][s2][s12])
        return dp[s1][s2][s12];
    vis[s1][s2][s12] = true;
    ld pn = 0;
    if(d <= n - s1 - s2 - s12)
        pn = esc[n - s1 - s2 - s12][d] / esc[n][d];
    ld r = 1.0 / (1.0 - pn);
    for(int i = 0; i <= s1; i++)
        for(int j = 0; j <= s2; j++)
            for(int k = 0; k <= s12; k++)
                if(d - i - j - k <= n - s1 - s2 - s12 && d >= i + j + k && i + j + k > 0)
                    r += (calc(s1 - i, s2 - j, s12 - k) * esc[s1][i] * esc[s2][j] * esc[s12][k] * esc[n - s1 - s2 - s12][d - i - j - k] / esc[n][d]) / (1.0 - pn);
    return dp[s1][s2][s12] = r;
}

int main(){
    set<int> ss1, ss2, ss12;
    scanf("%d %d %d", &n, &d, &c);
    for(int i = 0; i < c; i++){
        scanf("%d", &x);
        ss1.insert(x);
        ss12.insert(x);
    }
    for(int i = 0; i < c; i++){
        scanf("%d", &x);
        ss2.insert(x);
        ss12.insert(x);
    }
    int s1 = ss12.size() - ss2.size();
    int s2 = ss12.size() - ss1.size();
    int s12 = ss12.size() - s1 - s2;
    esc[0][0] = 1;
    for(int i = 1; i <= 50; i++){
        esc[i][0] = 1;
        for(int j = 1; j <= min(i, 10); j++)
            esc[i][j] = esc[i][j - 1] * (i - j + 1) / j;
    }
    printf("%.15Lf\n", calc(s1, s2, s12));
    return 0;
}
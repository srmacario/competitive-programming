#include <iostream>
using namespace std;

#define INF 1000000000

int dp[1<<10][64];

bool check(int m, int K) {
    int i, tmp1=0, tmp2=0;
    for (i=0; i<K; i++) tmp1 += ((m>>i)&1);
    for (i=0; i<K; i++) tmp2 += ((m>>(K+i))&1);
    return tmp1 == tmp2;
}

int main() {
    int N, M, K, i, j, k, t, T, a, b, c, d[64][64], RES, tmp;

    cin >> T;
    for (t=0; t<T; t++) {
        cin >> N >> M >> K;

        for (i=0; i<N; i++) {
            d[i][i] = 0;
            for (j=i+1; j<N; j++) d[i][j] = d[j][i] = INF;
        }

        for (i=0; i<M; i++) {
            cin >> a >> b >> c; a--; b--;
            d[a][b] = d[b][a] = min(c, min(d[a][b], d[b][a]));
        }

        for (k=0; k<N; k++) for (i=0; i<N; i++) for (j=0; j<N; j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

        for (i=0; i<(1<<(2*K)); i++) for (j=0; j<N; j++) dp[i][j] = INF;
        for (i=0; i<K; i++) for (j=0; j<N; j++) dp[1<<i][j] = d[i][j];
        for (i=0; i<K; i++) for (j=0; j<N; j++) dp[1<<(K+i)][j] = d[N-1-i][j];

        for (i=1; i<(1<<(2*K)); i++) {
            for (j=0; j<N; j++) {
                if (dp[i][j] != INF) continue;
    
                for (k=(i-1)&i; k; k=(k-1)&i) dp[i][j] = min(dp[i][j], dp[k][j]+dp[i^k][j]);
            }

            if (check(i, K)) {
                tmp = INF;
                for (j=0; j<N; j++) tmp = min(tmp, dp[i][j]);
                for (j=0; j<N; j++) dp[i][j] = tmp;
            } else {
                for (j=0; j<N; j++) for (k=0; k<N; k++) dp[i][j] = min(dp[i][j], dp[i][k] + d[k][j]);
            }
        }

        RES = INF;
        for (i=0; i<N; i++) RES = min(RES, dp[(1<<(2*K))-1][i]);
        if (RES < INF) cout << RES << endl;
        else cout << "No solution" << endl;
    }

    return 0;
}

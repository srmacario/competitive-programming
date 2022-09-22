#include<bits/stdc++.h>
using namespace std;

typedef short int si;

const int N = 505;

struct pos{
	si i, j, k;
	pos(si _i = 0, si _j = 0, si _k = 0) : i(_i), j(_j), k(_k){}
	bool operator ==(pos o){ return (i == o.i && j == o.j && k == o.k); }
	bool operator <(const pos &o) const{
		if(i != o.i) return i < o.i;
		if(j != o.j) return j < o.j;
		return k < o.k;
	}
} ini, fim;

si m, n, p;
bool vis[N][N][N];
si mi_ij[N][N], ma_ij[N][N], mi_ik[N][N], ma_ik[N][N], mi_jk[N][N], ma_jk[N][N];
si dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
queue<pos> q;

void put(si i, si j, si k){
	if(!vis[i][j][k]){
		q.push(pos(i, j, k));
		vis[i][j][k] = true;
	}
}

int bfs(){
	si i, j, k;
	int ans = 0, cnt = 1;
	while(!q.empty()){
		pos f = q.front();
		if(!cnt){
			ans++;
			cnt = q.size();
		}
		q.pop();
		cnt--;
		if(f == fim)
			return ans;
		i = f.i;
		j = f.j;
		k = f.k;
		if(i < 0 || j < 0 || k < 0 || i >= N || j >= N || k >= N)
			continue;
		if(mi_ij[i][j] > k)
			put(i, j, mi_ij[i][j] - 1);
		if(ma_ij[i][j] < k)
			put(i, j, ma_ij[i][j] + 1);
		if(mi_ik[i][k] > j)
			put(i, mi_ik[i][k] - 1, k);
		if(ma_ik[i][k] < j)
			put(i, ma_ik[i][k] + 1, k);
		if(mi_jk[j][k] > i)
			put(mi_jk[j][k] - 1, j, k);
		if(ma_jk[j][k] < i)
			put(ma_jk[j][k] + 1, j, k);
		for(int h = 0; h < 4; h++){
			int ii = i + dx[h], jj = j + dy[h];
			if(ii >= 0 && ii < N && jj >= 0 && jj < N){
				if(mi_ij[i][j] == k + 1 && mi_ij[ii][jj] > k)
					put(ii, jj, mi_ij[ii][jj] - 1);
				if(ma_ij[i][j] == k - 1 && ma_ij[ii][jj] < k)
					put(ii, jj, ma_ij[ii][jj] + 1);
			}
			
			int kk = k + dy[h];
			if(ii >= 0 && ii < N && kk >= 0 && kk < N){
				if(mi_ik[i][k] == j + 1 && mi_ik[ii][kk] > j)
					put(ii, mi_ik[ii][kk] - 1, kk);
				if(ma_ik[i][k] == j - 1 && ma_ik[ii][kk] < j)
					put(ii, ma_ik[ii][kk] + 1, kk);
			}

			jj = j + dx[h];
			if(kk >= 0 && kk < N && jj >= 0 && jj < N){
				if(mi_jk[j][k] == i + 1 && mi_jk[jj][kk] > i)
					put(mi_jk[jj][kk] - 1, jj, kk);
				if(ma_jk[j][k] == i - 1 && ma_jk[jj][kk] < i)
					put(ma_jk[jj][kk] + 1, jj, kk);
			}
		}
	}
	return -1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> m >> n >> p;
	for(si i = 0; i < N; i++)
		for(si j = 0; j < N; j++){
			ma_ij[i][j] = N;
			ma_jk[i][j] = N;
			ma_ik[i][j] = N;
		}
	for(si i = 1; i <= p; i++)
		for(si j = 1; j <= n; j++)
			for(si k = 1; k <= m; k++){
				char c;
                cin >> c;
				if(c == 'R')
					ini = pos(i, j, k);
				else if(c == 'T')
					fim = pos(i, j, k);
				else if(c == '*'){
					if(!mi_ij[i][j])
						mi_ij[i][j] = k;
					ma_ij[i][j] = k;
					if(!mi_ik[i][k])
						mi_ik[i][k] = j;
					ma_ik[i][k] = j;
					if(!mi_jk[j][k])
						mi_jk[j][k] = i;
					ma_jk[j][k] = i;
				}
			}
	q.push(ini);
	vis[ini.i][ini.j][ini.k] = true;
	cout << bfs() << "\n";
	return 0;
}
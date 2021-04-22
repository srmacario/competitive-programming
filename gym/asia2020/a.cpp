#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=505;

int t,n,tout, bx[N], by[N], ex[N], ey[N], grid[N][N];
char nd, dgrid[N][N];
map<int,int> eqx, eqy;
map<char, int> eqc;
set<int> ox,oy;
vector<int> vx, vy;

void pre_dfs(int x, int y, char d, int tat){
	if(x==eqx[bx[0]] && y==eqy[by[0]] && tat) tout=tat;
	else if(tat>t) tout=tat;
	else{
		if(grid[x][y]==2){
			if(d=='L') d='D';
			else if(d=='R') d='U';
			else if(d=='U') d='L';
			else d='R';
		}
		else if(grid[x][y]==3) d=dgrid[x][y];
		if(d=='L') pre_dfs(x-1, y, d, tat+vx[x]-vx[x-1]);
		else if(d=='R') pre_dfs(x+1, y, d, tat+vx[x+1]-vx[x]);
		else if(d=='U') pre_dfs(x, y+1, d, tat+vy[y+1]-vy[y]);
		else pre_dfs(x, y-1, d, tat+vy[y]-vy[y-1]);
	}
}

void dfs(int x, int y, char d){
	if(grid[x][y]==2){
		if(d=='L') d='D';
		else if(d=='R') d='U';
		else if(d=='U') d='L';
		else d='R';
	}
	else if(grid[x][y]==3) d=dgrid[x][y];
	if(d=='L'){
		if(vx[x]-vx[x-1]>=t) printf("%d %d\n", vx[x]-t, vy[y]);
		else{
			t-=vx[x]-vx[x-1];
			dfs(x-1, y, d);
		}
	}
	else if(d=='R'){
		if(vx[x+1]-vx[x]>=t) printf("%d %d\n", vx[x]+t, vy[y]);
		else{
			t-=vx[x+1]-vx[x];
			dfs(x+1, y, d);
		}
	}
	else if(d=='U'){
		if(vy[y+1]-vy[y]>=t) printf("%d %d\n", vx[x], vy[y]+t);
		else{
			t-=vy[y+1]-vy[y];
			dfs(x, y+1, d);
		}
	}
	else{
		if(vy[y]-vy[y-1]>=t) printf("%d %d\n", vx[x], vy[y]-t);
		else{
			t-=vy[y]-vy[y-1];
			dfs(x, y-1, d);
		}
	}
}

int main(){
	scanf("%d %d", &n, &t);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d", &bx[i], &by[i], &ex[i], &ey[i]);
		ox.insert(bx[i]);
		ox.insert(ex[i]);
		oy.insert(by[i]);
		oy.insert(ey[i]);
	}
	for(int i:ox){
		eqx[i]=vx.size();
		vx.push_back(i);
	}
	for(int i:oy){
		eqy[i]=vy.size();
		vy.push_back(i);
	}
	for(int i=0;i<n;i++){
		grid[eqx[bx[i]]][eqy[by[i]]]=3;
		grid[eqx[ex[i]]][eqy[ey[i]]]=3;
		for(int j=min(eqx[bx[i]], eqx[ex[i]])+1;j<max(eqx[bx[i]],eqx[ex[i]]);j++) grid[j][eqy[by[i]]]++;
		for(int j=min(eqy[by[i]], eqy[ey[i]])+1;j<max(eqy[by[i]],eqy[ey[i]]);j++) grid[eqx[bx[i]]][j]++;
		if(eqx[bx[i]]<eqx[ex[i]]){
			dgrid[eqx[bx[i]]][eqy[by[i]]]='R';
			dgrid[eqx[ex[i]]][eqy[by[i]]]='L';
		}
		if(eqx[bx[i]]>eqx[ex[i]]){
			dgrid[eqx[bx[i]]][eqy[by[i]]]='L';
			dgrid[eqx[ex[i]]][eqy[by[i]]]='R';
		}
		if(eqy[by[i]]<eqy[ey[i]]){
			dgrid[eqx[bx[i]]][eqy[by[i]]]='U';
			dgrid[eqx[ex[i]]][eqy[ey[i]]]='D';
		}
		if(eqy[by[i]]>eqy[ey[i]]){
			dgrid[eqx[bx[i]]][eqy[by[i]]]='D';
			dgrid[eqx[ex[i]]][eqy[ey[i]]]='U';
		}
	}
	pre_dfs(eqx[bx[0]], eqy[by[0]], dgrid[eqx[bx[0]]][eqy[by[0]]], 0);
	t%=tout;
	dfs(eqx[bx[0]],eqy[by[0]], dgrid[eqx[bx[0]]][eqy[by[0]]]);
	return 0;
}
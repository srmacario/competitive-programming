#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int n, m, ansx, ansy, qw, ql[N], qc[N], grid[N][N];
bool l[N], c[N];
char s;

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c", &s);
			if(s=='*'){
				grid[i][j]=1;
				qw++;
				ql[i]++;
				qc[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ql[i]+qc[j]-grid[i][j]==qw){
				printf("YES\n%d %d\n", i+1, j+1);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}

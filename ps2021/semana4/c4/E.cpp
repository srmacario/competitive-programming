#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n, q, c, x[N], y[N], s[N], mat[15][110][110], t, llx, lly, urx, ury;

int main(){
	scanf("%d %d %d", &n, &q, &c);
	c++;
	for(int i=0;i<n;i++) scanf("%d %d %d", &x[i], &y[i], &s[i]);
	for(int i=0;i<c;i++){
		for(int j=0;j<n;j++) mat[i][x[j]][y[j]]+=(s[j]+i)%c;
		for(int j=1;j<=100;j++) for(int k=1;k<=100;k++) mat[i][j][k]+=mat[i][j-1][k]+mat[i][j][k-1]-mat[i][j-1][k-1];
	}
	while(q--){
		scanf("%d %d %d %d %d", &t, &llx, &lly, &urx, &ury);
		printf("%d\n", mat[t%c][urx][ury]-mat[t%c][urx][lly-1]-mat[t%c][llx-1][ury]+mat[t%c][llx-1][lly-1]);
	}
}

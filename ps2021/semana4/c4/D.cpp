#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int x[3],y[3],d[3];

int dist(int i, int j){ return (x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]); }

bool val(){
	for(int i=0;i<3;i++) d[i]=dist(i,(i+1)%3);
	sort(d,d+3);
	return d[0] && d[0]+d[1]==d[2];
}

int main(){
	for(int i=0;i<3;i++) scanf("%d %d", &x[i], &y[i]);
	if(val()) printf("RIGHT\n");
	else{
		bool ar=false;
		for(int i=0;i<3;i++){
			x[i]++;
			if(val()) ar=true;
			x[i]-=2;
			if(val()) ar=true;
			x[i]++;
			y[i]++;
			if(val()) ar=true;
			y[i]-=2;
			if(val()) ar=true;
			y[i]++;
		}
		if(ar) printf("ALMOST\n");
		else printf("NEITHER\n");
	}
}

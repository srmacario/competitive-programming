#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-6;

ld h, w, f, a, b, c;

ld ff(ld x){
	return sqrt(4.0 * x * x * a * a + 4.0 * a * b * x + b * b + 1.0);
}

ld simpson(ld aa){
	int n = 1e3;
	ld bb = w / 2; 
	ld hh = (bb - aa) / n;
	ld s = ff(aa) + ff(bb);
	for(int i = 1; i < n; i += 2) s += 4 * ff(aa + hh * i);
	for(int i = 2; i < n; i += 2) s += 2 * ff(aa + hh * i);
	return s * hh / 3;
}

ld fff(ld x){
	return simpson(x) + x * f;
}

ld ts(ld l, ld r){
	for(int i = 0; i < 300; i++){
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;
		if(fff(m1) > fff(m2))
			l = m1;
		else
			r = m2;
	}
	return l;
}

ld calcy(ld x){
	return a * x * x + b * x + c;
}

int main(){
	scanf("%Lf %Lf %Lf", &h, &w, &f);
	while(h > EPS || w > EPS || f > EPS){
		a = 4.0 * h / w / w;
		b = -4.0 * h / w;
		c = h;
		printf("%.3Lf\n", calcy(ts(0, w / 2)));
		scanf("%Lf %Lf %Lf", &h, &w, &f);
	}
	return 0;
}
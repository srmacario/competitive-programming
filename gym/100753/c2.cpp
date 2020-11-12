

    #include <bits/stdc++.h>
    using namespace std;
     
    int n;
    long double a,x[110],y[110];
     
    long double area(int i, int j, int k){
    	return abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-x[j]*y[i]-x[k]*y[j]-x[i]*y[k]);
    }
     
    long double st(){
    	long double r;
    	r=area(n-1,0,1)+area(n-2,n-1,0);
    	for(int i=1;i<n-1;i++) r+=area(i-1,i,i+1);
    	return abs(r);
    }
     
    long double sT(){
    	long double r=x[n-1]*y[0]-x[0]*y[n-1];
    	for(int i=0;i<n-1;i++) r+=x[i]*y[i+1]-x[i+1]*y[i];
    	return abs(r);
    }
     
    int main(){
        scanf("%Lf %d", &a, &n);
        a=1-a;
        for(int i=0;i<n;i++) scanf("%Lf %Lf", &x[i], &y[i]);
        printf("%0.5Lf\n", sqrt(st()/(a*sT())));
        return 0;
    }
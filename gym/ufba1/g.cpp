#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=2e5+5;

int n;
double xf,alf,t,d,x,y;

int main(){
    scanf("%d %lf", &n, &xf);
    scanf("%lf %lf %lf", &alf, &t, &d);
    alf=acos(0.0)/double(180);
    t=double(360)/t;
    //double q=
    while(n--){
        double r=0.0;
        scanf("%lf %lf", &x, &y);
        if(x*x+y*y>d*d){
            printf("%lf\n", r);
            continue;
        }
        double angi=acos(x/sqrt(x*x+y*y));
        double t1=(angi-alf)/t,t2=(angi+alf)/t;
        if(t1>xf){
            printf("%lf\n", r);
            continue;
        }
        if(t2>xf) t2=xf;
        if(t1<0) t1=0.0;
        printf("%lf\n", t2-t1);
    }
    return 0;
}
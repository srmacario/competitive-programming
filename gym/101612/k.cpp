#include<bits/stdc++.h>
using namespace std;

bool wrk(long long a, long long b, long long n){
    if(n%a or n%b) return 0;
    while(n%a==0) n/=a;
    while(n%b==0) n/=b;
    return n==1;
}

vector<long long> mk(long long a, long long b, long long n){
 vector<long long> h;
 while(n%a==0){
  h.push_back(a);
  n/=a;
 }
 while(n%b==0){
  h.push_back(b);
  n/=b;
 }
 return h;
}

long long binS(long long n){
 long long lo=0, hi=1e9, mid;
 while(lo<hi){
  mid=(lo+hi+1)/2;
  if(mid*mid>n) hi=mid-1;
  else lo=mid;
 }
 return lo;
}

int main(){
 FILE *in , *out;
 in = fopen("little.in","r") , out = fopen("little.out","w");
 long long n,auxn;
 fscanf(in,"%lld", &n);
 auxn=n;
 if(wrk(2,2,n)) fprintf(out,"-1\n");
 else{
  vector<vector<long long>> r;
  for(long long i=2;i*i*i<=n;i++){
   if(wrk(i,i,n)) r.push_back(mk(i,i,n));
   else if(wrk(i,i+1,n)) r.push_back(mk(i,i+1,n));
  }
  r.push_back(mk(n,n,n));
  long long h=binS(n);
  if(wrk(h,h,n)) r.push_back(mk(h,h,n));
  else if(wrk(h,h+1,n)) r.push_back(mk(h,h+1,n));
  fprintf(out,"%d\n", (int)r.size());
  for(int i=0;i<r.size();i++){
   fprintf(out,"%d", (int)r[i].size());
   for(int j=0;j<r[i].size();j++) fprintf(out," %lld", r[i][j]);
   fprintf(out,"\n");
  }
 }
 return 0;
}

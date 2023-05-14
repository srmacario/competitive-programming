#include<bits/stdc++.h>
using namespace std;

bool wrk(long long a, long long b, long long n){
    if(n%a || n%b) return false;
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

long long binSs(long long n){
    long long lo=1e6+1, hi=1e9, mid;
    while(lo<hi){
        mid=(lo+hi)/2;
          if(mid*mid>=n) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

long long binSd(long long n){
    long long lo=1e6+1, hi=1e9, mid;
    while(lo<hi){
        mid=(lo+hi)/2;
          if(mid*(mid+1)>=n) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main(){
     FILE *in , *out;
     in = fopen("little.in","r") , out = fopen("little.out","w");
     long long n;
     fscanf(in,"%lld", &n);
     if(wrk(2,2,n) || n==1) fprintf(out,"-1\n");
    else{
          vector<vector<long long>> r;
          for(long long i=2;i<=1e6;i++){
               if(wrk(i,i,n)) r.push_back(mk(i,i,n));
              if(wrk(i,i+1,n)) r.push_back(mk(i,i+1,n));
          }
          if(n > 1e6)r.push_back(mk(n,n,n));
          long long h=binSs(n);
          if(wrk(h,h,n)) r.push_back(mk(h,h,n));
          h=binSd(n);
          if(wrk(h,h+1,n)) r.push_back(mk(h,h+1,n));
          fprintf(out,"%d\n", (int)r.size());
          for(int i=0;i<r.size();i++){
               fprintf(out,"%d", (int)r[i].size());
               for(int j=0;j<r[i].size();j++) fprintf(out," %lld", r[i][j]);
               fprintf(out,"\n");
        }
    }
    return 0;
}
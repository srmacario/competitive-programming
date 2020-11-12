#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const int N = 1e6+5;

int n , vis[N] , dv[N];
set<int> E;
vector<int> A , resp , resp2;
vector<pii> S;

bool comp(pii a , pii b){
  if(a.nd < b.nd) return true;
  if(a.nd == b.nd && a.st < b.st) return true;
  return false;
}

int main(){

  FILE *in , *out;
  in = fopen("equal.in","r") , out = fopen("equal.out","w");

  fscanf(in,"%d",&n);
  for(int i = 0 ; i < n ; i++){
    int x;
    fscanf(in,"%d",&x);
    E.insert(x);
    vis[x]++;
  }

  if(E.size() == 1){
    for(int i = 0 ; i <= n ; i++) fprintf(out,"1 ");
    fprintf(out,"\n");
    return 0;
  }

  for(auto v : E) A.pb(v);

  dv[1] = 1;
  for(int i = 0 ; i < A.size() ; i++){

    bool ok = true;
    for(int j = 2 ; j*j <= A[i] ; j++)
      if(A[i]%j == 0 && vis[j]){dv[j] = 1; break;}

  }

  for(int i = 0 ; i < A.size() ; i++)
    S.pb({vis[A[i]],!dv[A[i]]});

  sort(S.begin(),S.end());

  //for(int i = 0 ; i < S.size() ; i++) cout << S[i].st << " " << S[i].nd << "\n";

  for(int i = 0 ; i < S[0].st+S[1].st ; i++) resp.pb(S.size());
  for(int i = 2 ; i < S.size() ; i++)
    for(int j = 0 ; j < S[i].st ; j++) resp.pb(S.size()-i+1);
  resp.pb(1);

  sort(S.begin(),S.end(),comp);
  //for(int i = 0 ; i < S.size() ; i++) cout << S[i].st << " " << S[i].nd << "\n";
  for(int i = 0 ; i < S.size() ; i++){
    if(S[i].nd == 0)
      for(int j = 0 ; j < S[i].st ; j++) resp2.pb(S.size()-i);
  }
  if(!resp2.empty()) resp2.pb(resp2.back()-1);
  /*for(int i = 0 ; i < resp2.size() ; i++) cout << resp2[i] << " ";
  cout << "\n";*/

  for(int i = 0 ; i < resp.size() ; i++){
    if(i < resp2.size()) fprintf(out,"%d ",min(resp[i],resp2[i]));
    else if(!resp2.empty()) fprintf(out,"%d ",min(resp[i],resp2.back()));
    else fprintf(out,"%d ",resp[i]);
  }
  fprintf(out,"\n");
  

}

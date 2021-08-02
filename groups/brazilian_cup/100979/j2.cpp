#include<bits/stdc++.h>
using namespace std;

int pn,nn,m,qn,qp,qmeh;
string prod,s,f;
set<string> p,n;

string minusc(string c){
 for(int i=0;i<c.size();i++) if(c[i]>='A' && c[i]<='Z') c[i]=c[i]-'A'+'a';
 return c;
}

int main(){
 cin>>s;
 prod=minusc(s);
 cin>>pn;
 for(int i=0;i<pn;i++){
  cin>>s;
  p.insert(minusc(s));
 }
 cin>>nn;
 for(int i=0;i<nn;i++){
  cin>>s;
  n.insert(minusc(s));
 }
 cin>>m;
 char c;
getline(cin,f);
 for(int i=0;i<m;i++){
  getline(cin,f);
  s.clear();
  int h=0;
  bool val=false;
  for(int j=0;j<f.size();j++){
   if(f[j]==' '){
    if(minusc(s)==prod) val=true;
    if(p.count(minusc(s))) h++;
    if(n.count(minusc(s))) h--;
    s.clear();
   }
   else s+=f[j];
  }
  if(minusc(s)==prod) val=true;
  if(p.count(minusc(s))) h++;
  if(n.count(minusc(s))) h--;
  if(val){
   if(h>0) qp++;
   else if(h<0) qn++;
   else qmeh++;
  }
 }
 printf("%d %d %d\n", qp, qmeh, qn);
 return 0;
}
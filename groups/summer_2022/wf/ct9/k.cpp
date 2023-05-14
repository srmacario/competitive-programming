#include<bits/stdc++.h>
using namespace std;

const int N = 4e2;
const int M = 4e2;

bool r[N];

bool gauss_elimination(int n, int m, vector<vector<bool>> eq, vector<bool> &ans){
 for(int i = 0; i < m; i++)
  ans[i] = true;
 int lid[N] = {0};
 int l = 0;
 for(int i = m - 1; i >= 0; i--){
  for(int j = l; j < n; j++)
   if(eq[j][i]){
    swap(eq[l], eq[j]);
    swap(r[l], r[j]);
   }
  if(l == n || !eq[l][i])
   continue;
  lid[l] = i + 1;
  for(int j = l + 1; j < n; j++){
   if(!eq[j][i])
    continue;
   for(int k = 0; k <= i; k++)
    eq[j][k] ^= eq[l][k];
   r[j] ^= r[l];
  }
  l++;
 }
 for(int i = n - 1; i >= 0; i--){
  for(int j = 0; j < lid[i + 1]; j++)
   r[i] ^= (eq[i][j] && ans[j]);
  for(int j = lid[i + 1]; j + 1 < lid[i]; j++){
   ans[j] = true;
   r[i] ^= eq[i][j];
  }
  if(lid[i])
   ans[lid[i] - 1] = r[i];
  else if(r[i])
   return false;
 }
 return true;
}

int main(){
 vector<vector<bool>> eq;
 vector<bool> ans(M), r(N);
 eq.resize(N);
 for(int i = 0; i < N; i++)
  eq[i].resize(M);
 int n, m;
 scanf("%d %d", &m, &n);
 while(n != 0){
  for(int i = 0; i < n; i++)
   for(int j = 0; j < m; j++){
    scanf("%d", &r[m * i + j]);
    r[m * i + j] ^= 1;
   }
  for(int i = 0; i < n * m; i++){
   for(int j = 0; j < n * m; j++)
    eq[i][j] = 0;
   eq[i][i] = 1;
   if(i % m)
    eq[i][i - 1] = 1;
   if(i % m < m - 1)
    eq[i][i + 1] = 1;
   if(i >= m)
    eq[i][i - m] = 1;
   if(i < m * (n - 1))
    eq[i][i + m] = 1;
  }
  if(gauss_elimination(n * m, n * m, eq, r, ans)){
   vector<int> v;
   for(int i = 0; i < n * m; i++)
    if(ans[i])
     v.push_back(i);
   printf("%d\n", v.size());
   for(int i : v)
    printf("%d %d\n", i / m + 1, i % m + 1);
  }
  else
   printf("-1\n");
  scanf("%d %d", &m, &n);
 }
 return 0;
}
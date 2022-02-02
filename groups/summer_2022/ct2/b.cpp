#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

const int N = 1e3 + 5;

typedef long double ld;

pair <ld, ld> p[3];

ld C[N][2*N + 1], m[N][N]; // N = 1000, M = 2*N+1;
int row, col;

bool elim() {
  for(int i = 0; i < row; ++i) {
    int p = i; // Choose the biggest pivot
    for(int j=i; j<row; ++j) if (abs(C[j][i]) > abs(C[p][i])) p = j;
    for(int j=i; j<col; ++j) swap(C[i][j], C[p][j]);

    if (!C[i][i]) return 0;

    ld c = 1/C[i][i]; // Normalize pivot line
    for(int j=0; j<col; ++j) C[i][j] *= c;

    for(int k=i+1; k<col; ++k) {
      ld c = -C[k][i]; // Remove pivot variable from other lines
      for(int j=0; j<col; ++j) C[k][j] += c*C[i][j];
    }
  }

  // Make triangular system a diagonal one
  for(int i=row-1; i>=0; --i) for(int j=i-1; j>=0; --j) {
    ld c = -C[j][i];
    for(int k=i; k<col; ++k) C[j][k] += c*C[i][k];
  }

  return 1;
}

ld x[N], y[N];

// Solves linear system m*x = y, of size n x n
bool linear_system(int n, ld m[N][N]) {
  for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) C[i][j] = m[i][j];
  for(int j = 0; j < n; ++j) C[j][n] = x[j];

  row = n, col = n+1;
  bool ok = elim();

  for(int j=0; j<n; ++j) y[j] = C[j][n];
  return ok;
}

void new_coef(ld &A, ld &B, ld &C, ld &D, ld &E, ld &F){
  ld a = A, b = B, c = C, d = D, e = E, f = F, angle;
  ld cte_pos = sqrt(0.5 * (1.0 + abs(a - c) / sqrt((a - c) * (a - c) + b*b)));
  ld cte_neg = sqrt(0.5 * (1.0 - abs(a - c) / sqrt((a - c) * (a - c) + b*b)));
  if(a > c){
    A = (a + c)/2 + 0.5 * sqrt((a - c) * (a - c) + b*b);
    C = (a + c)/2 - 0.5 * sqrt((a - c) * (a - c) + b*b);
    D = d * cte_pos + e * cte_neg;
    E = e * cte_neg - d * cte_neg;
  }
  else{
    A = (a + c)/2 + 0.5 * sqrt((a - c) * (a - c) - b*b);
    C = (a + c)/2 - 0.5 * sqrt((a - c) * (a - c) - b*b);
    D = d * cte_pos - e * cte_neg;
    E = e * cte_neg + d * cte_neg;
  }
  B = 0;
}

pair<ld, ld> elipse(ld A, ld B, ld C, ld D, ld E, ld F){
  ld a, b;
  ld cte = -F + (D * D / 4 * A + E * E / 4 * C);
  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cin >> p[j].st >> p[j].nd;
        }
        int eq = 0;
        //elipse from text: x² + Bxy + Cy² + Dx + Ey + F = 0
        for(int j = 0; j < 3; j++){
            pair<ld, ld> pt = {(p[j].st + p[(j + 1)%3].st) / 2, (p[j].nd + p[(j + 1)%3].nd) / 2};
            m[eq][0] = pt.st * pt.nd; //B
            m[eq][1] = pt.nd * pt.nd; //C
            m[eq][2] = pt.st; //D
            m[eq][3] = pt.nd; //E
            m[eq][4] = 1; //F
            x[eq] = - pt.st * pt.st;
            eq++;
        }
        //tangent: 2x + B(y + xy') + C2yy' + D + Ey' = 0
        for(int j = 0; j < 3; j++){
            if(eq == 5) break;
            if(p[j].st == p[(j + 1)%3].st) continue;
            pair<ld, ld> pt = {(p[j].st + p[(j + 1)%3].st) / 2, (p[j].nd + p[(j + 1)%3].nd) / 2};
            ld tg = (p[j].nd - p[(j + 1)%3].nd) / (p[j].st - p[(j + 1)%3].st);
            m[eq][0] = pt.nd + pt.st * tg; //B
            m[eq][1] = 2 * pt.nd * tg; //C
            m[eq][2] = 1; //D
            m[eq][3] = tg; //E
            x[eq] = - 2 * pt.st;
            eq++;
        }
        cout << linear_system(5, m) << "\n";
        for(int j = 0; j < 3; j++){
            pair<ld, ld> pt = {(p[j].st + p[(j + 1)%3].st) / 2, (p[j].nd + p[(j + 1)%3].nd) / 2};
            cout << (pt.st * pt.st) + y[0] * pt.st * pt.nd + y[1] * pt.nd * pt.nd + y[2] * pt.st + y[3] * pt.nd + y[4] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
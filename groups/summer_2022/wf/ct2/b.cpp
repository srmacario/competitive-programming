#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

const int N = 10;

typedef long double ld;

const ld EPS = 1e-9;

pair <ld, ld> p[3];

struct pt {
  ld x, y;
  pt(ld xx = 0, ld yy = 0) {
          x = xx; y = yy;
  }
} f[2], fr[2];

pt rot(const pt &p, const ld &theta) {
       return pt(p.y*sin(theta) + p.x*cos(theta), p.y*cos(theta) - p.x*sin(theta));
}

bool operator<(const pt &p1, const pt &p2) {
       if (abs(p1.x - p2.x) > EPS) return p1.x < p2.x;
       else return p1.y < p2.y;
}

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

/*pair<ld, ld> elipse(ld A, ld B, ld C, ld D, ld E, ld F){
  ld a, b;
  ld cte = -F + (D * D / 4 * A + E * E / 4 * C);
  
}*/

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
            m[eq][0] = pt.st * pt.st;
            m[eq][1] = pt.st * pt.nd; //B
            m[eq][2] = pt.nd * pt.nd; //C
            m[eq][3] = pt.st; //D
            m[eq][4] = pt.nd; //E
            x[eq] = 1; //F
            eq++;
        }
        //tangent: 2x + B(y + xy') + C2yy' + D + Ey' = 0
        for(int j = 0; j < 3; j++){
            if(eq == 5) break;
            if(p[j].st == p[(j + 1)%3].st) continue;
            pair<ld, ld> pt = {(p[j].st + p[(j + 1)%3].st) / 2, (p[j].nd + p[(j + 1)%3].nd) / 2};
            ld tg = (p[j].nd - p[(j + 1)%3].nd) / (p[j].st - p[(j + 1)%3].st);
            m[eq][0] = 2 * pt.st;
            m[eq][1] = pt.nd + pt.st * tg; //B
            m[eq][2] = 2 * pt.nd * tg; //C
            m[eq][3] = 1; //D
            m[eq][4] = tg; //E
            x[eq] = 0;
            eq++;
        }
        linear_system(5, m);
        ld a, b, c, d, e, theta, av, au, bv, bu, v0, u0, tmp, sv, su, d2, l, s, S;
        a = y[0];
        b = y[1];
        c = y[2];
        d = y[3];
        e = y[4];
        //from: Ax² + Cy² + Dx + Ey = 1
        //find eq with formula: A(x + D/2A)² + C(y + E/2A)² = 1 + D²/4A + E²/4C 
        //if its not rotated, rotate
        if (abs(b) > EPS) {
          theta = atan2(b, c-a)/2.0;

          av = (a + c + b/sin(2.0*theta))/2.0; // A
          au = (a + c - b/sin(2.0*theta))/2.0; // C

          bv = d*sin(theta) + e*cos(theta); // D
          bu = d*cos(theta) - e*sin(theta); // E
          //F = 1
        } else {
          au = a;
          av = c;
  
          bu = d;
          bv = e;
        }
        //center of elipse
        v0 = -bv/(2.0 * av);
        u0 = -bu/(2.0 * au);
        
        //calc a and b from elipse
        tmp = 1.0 + (bv * bv)/(4.0 * av) + (bu * bu)/(4.0 * au);
        sv = tmp/av; // a
        su = tmp/au; // b
        
        //swap if a < b
        s = min(sv, su); S = max(sv, su);
        //c : distance between center and focus
        d2 = sqrt(S - s);
        l = 2.0*sqrt(S);
        
        //calc focus
        for (int i=0; i<2; i++) {
          fr[i].x = u0;
          fr[i].y = v0;
        }
        if (su == S) {
          fr[0].x += d2;
          fr[1].x -= d2;
        } else {
          fr[0].y += d2;
          fr[1].y -= d2;
        }
        
        //re-rotate
        if (abs(b) > EPS) for (int i=0; i<2; i++) f[i] = rot(fr[i], theta);
        else for (int i=0; i<2; i++) f[i] = fr[i];
        
        //answer
        if (f[1] < f[0]) swap(f[0], f[1]);
        cout << i << setprecision(2) << fixed << " " << f[0].x << " " << f[0].y << " " << f[1].x << " " << f[1].y << " " << l << "\n";
    }
    return 0;
} 
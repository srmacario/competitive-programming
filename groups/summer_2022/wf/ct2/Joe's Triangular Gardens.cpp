#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef double tint;

#define EPS 1E-9
#define ZERO 0.0
#define SQ(x) ( (x)*(x) )
#define ABS(x) ( (x)<ZERO ? -(x) : (x) )

struct pt {
       tint x, y;
       pt(tint xx=ZERO, tint yy=ZERO) {
               x = xx; y = yy;
       }
} p[3], m[3], f[2], fr[2];

pt operator+(const pt &p1, const pt &p2) {return pt(p1.x+p2.x, p1.y+p2.y);}
pt operator/(const pt &p, const tint d) {return pt(p.x/d, p.y/d);}
bool operator<(const pt &p1, const pt &p2) {
       if (abs(p1.x - p2.x) > EPS) return p1.x < p2.x;
       else return p1.y < p2.y;
}

bool gauss_jordan(tint **A, int N, tint **B, int M) {
       int i, j, k, jmax;
       double tmp;

       for (i=1; i<=N; i++) {
               //Encontrar el maximo elemento de A en la columna i con fila >= i
               jmax = i;
               for (j=i+1; j<=N; j++) {
                       if (ABS(A[j][i]) > ABS(A[jmax][i])) jmax = j;
               }

               //Intercambiar las filas i y jmax
               for (j=1; j<=N; j++) swap(A[i][j], A[jmax][j]);
               for (j=1; j<=M; j++) swap(B[i][j], B[jmax][j]);

               //Controlar que la matriz sea invertible
               if (A[i][i] == 0.0) return false;

               //Normalizar la fila i
               tmp = A[i][i];
               for (j=1; j<=N; j++) A[i][j] /= tmp;
               for (j=1; j<=M; j++) B[i][j] /= tmp;

               //Eliminar los valores no nulos de la columna i
               for (j=1; j<=N; j++) {
                       if (i == j) continue;

                       tmp = A[j][i];
                       for (k=1; k<=N; k++) A[j][k] -= A[i][k]*tmp;
                       for (k=1; k<=M; k++) B[j][k] -= B[i][k]*tmp;
               }
       }
       return true;
}

tint A[8][8], B[8][8];

void print(const pt &p) {
       printf("{%.2lf, %.2lf}", p.x, p.y);
}

pt rot(const pt &p, const tint &theta) {
       return pt(p.y*sin(theta) + p.x*cos(theta), p.y*cos(theta) - p.x*sin(theta));
}

int main() {

    //freopen("in.txt", "r", stdin);
    
    int i, t, T;
    tint *AA[8], *BB[8], yp[2], a, b, c, d, e, theta, av, au, bv, bu, v0, u0, tmp, sv, su, d2, l, s, S;
    
    for (i=0; i<8; i++) {AA[i] = A[i]; BB[i] = B[i];}
    
    cin >> T;
    
    for (t=0; t<T; t++) {
    
        for (i=0; i<3; i++) {
               cin >> p[i].x;
               cin >> p[i].y;
        }
        if (p[0].x == p[1].x) swap(p[0], p[2]);
        else if (p[0].x == p[2].x) swap(p[0], p[1]);
        
        /*for (i=0; i<3; i++) {
               cout << "p[" << i << "] = "; print(p[i]); cout << endl;
        }
        cout << endl;*/
        
        yp[0] = (p[1].y - p[0].y)/(p[1].x - p[0].x);
        yp[1] = (p[2].y - p[0].y)/(p[2].x - p[0].x);
        
        m[0] = (p[0]+p[1])/2.0;
        m[1] = (p[0]+p[2])/2.0;
        m[2] = (p[1]+p[2])/2.0;
        
        /*for (i=0; i<3; i++) {
               cout << "m[" << i << "] = "; print(m[i]); cout << endl;
        }
        cout << endl;*/
        
        for (i=0; i<3; i++) {
               A[i+1][1] = SQ(m[i].x);
               A[i+1][2] = m[i].x*m[i].y;
               A[i+1][3] = SQ(m[i].y);
               A[i+1][4] = m[i].x;
               A[i+1][5] = m[i].y;
               B[i+1][1] = 1.0;
        }
        
        for (i=0; i<2; i++) {
               A[i+4][1] = 2.0*m[i].x;
               A[i+4][2] = m[i].x*yp[i] + m[i].y;
               A[i+4][3] = 2.0*m[i].y*yp[i];
               A[i+4][4] = 1.0;
               A[i+4][5] = yp[i];
               B[i+4][1] = 0.0;
        }
        
        /*for (i=1; i<=5; i++) {\
               cout << "{";
               for (int j=1; j<=5; j++) {
                       printf("%.2lf, ", A[i][j]);
               }
               cout << "}, " << endl;
        }
        cout << endl;*/
        
        gauss_jordan(AA, 5, BB, 1);
        
        a = B[1][1];
        b = B[2][1];
        c = B[3][1];
        d = B[4][1];
        e = B[5][1];
        
        printf("a=%.5lf\nb=%.5lf\nc=%.5lf\nd=%.5lf\ne=%.5lf\n\n", a, b, c, d, e);
        
        if (abs(b) > EPS) {
               theta = atan2(b, c-a)/2.0;
        
               av = a + c + b/sin(2.0*theta);
               au = a + c - b/sin(2.0*theta);
        
               bv = d*sin(theta) + e*cos(theta);
               bu = d*cos(theta) - e*sin(theta);
        } else {
               au = 2.0*a;
               av = 2.0*c;
        
               bu = d;
               bv = e;
        }
        
        v0 = -bv/av;
        u0 = -bu/au;
        
        tmp = 2.0 + SQ(bv)/av + SQ(bu)/au;
        sv = tmp/av;
        su = tmp/au;
        
        s = min(sv, su); S = max(sv, su);
        
        d2 = sqrt(S - s);
        l = 2.0*sqrt(S);
        
        for (i=0; i<2; i++) {
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
        
        if (abs(b) > EPS) for (i=0; i<2; i++) f[i] = rot(fr[i], theta);
        else for (i=0; i<2; i++) f[i] = fr[i];
        
        if (f[1] < f[0]) swap(f[0], f[1]);
//        cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
        
        printf("%d %.2lf %.2lf %.2lf %.2lf %.2lf\n", t+1, f[0].x, f[0].y, f[1].x, f[1].y, l);
    
    }

    return 0;
}

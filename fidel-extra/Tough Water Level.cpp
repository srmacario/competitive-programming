#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

#define SIGN(c) ( (c)=='+' ? 1.0 : -1.0 )
#define OPER(c) ( (c)=='*' ? true : false )
#define ISVALID(c) ( (c)=='.' ? true : ( (c)>='0' && (c)<='9' ) )
#define SQ(x) ( (x)*(x) )

#define MAXN 1024
#define TOTALSTEPS 1000
#define EPS 1E-9

typedef double tint;

const tint pi = 2.0*acos(0.0);

char *input;
int pos;

struct pt {
    tint M, Mx;
    pt(tint MM=0.0, tint MMxx=0.0) {
        Mx = MMxx; M = MM;
    }
};

pt operator+(const pt &p1, const pt &p2) {
    return pt(p1.M+p2.M, p1.Mx+p2.Mx);
}

pt operator-(const pt &p1, const pt &p2) {
    return pt(p1.M-p2.M, p1.Mx-p2.Mx);
}

pt operator*(const pt &p, const tint &a) {
    return pt(p.M*a, p.Mx*a);
}

tint expr(tint x);

tint readnum() {
    tint RES;
    string tmp = "";
    while (ISVALID(input[pos])) tmp += input[pos++];
    sscanf(tmp.c_str(), "%lf", &RES);
    return RES;
}

tint literal(tint x) {
//    cout << "reading literal " << input+pos << endl;
    tint RES;
    if (input[pos] == 'x') {RES = x; pos++;}
    else RES = readnum();
//    cout << "result of litaral is " << RES << endl;
    return RES;
}

tint factor(tint x) {
//    cout << "reading factor " << input+pos << endl;
    tint RES;
    if (input[pos] == '(') {
        pos++;
        RES = expr(x);
        pos++;
    } else RES = literal(x);
//    cout << "result of factor is " << RES << endl;
    return RES;
}

tint term(tint x) {
//    cout << "reading term " << input+pos << endl;
    tint RES = factor(x);
    while (input[pos] == '*' || input[pos] == '/') {
        bool oper = OPER(input[pos++]);
        if (oper) RES *= factor(x);
        else RES /= factor(x);
    }
//    cout << "result of term is " << RES << endl;
    return RES;
}

tint expr(tint x) {
//    cout << "reading expr " << input+pos << endl;
    tint RES = term(x);
    while (input[pos] == '+' || input[pos] == '-') {
        tint sign = SIGN(input[pos++]);
        RES += sign*term(x);
    }
//    cout << "result of expr is " << RES << endl;
    return RES;
}

pt integrate(char inp[], tint x_low, tint x_high, int STEPS) {
    tint x, M, Mx, tmp, dx=(x_high-x_low)/STEPS;

    input = inp; M = Mx = 0.0;
    x = x_low + dx/2.0;
    for (int i=0; i<STEPS; i++) {
        pos = 0;
        tmp = expr(x); tmp = SQ(tmp);
        M += tmp*dx;
        Mx  += x*tmp*dx;
        x += dx;
    }
    return pt(M, Mx);
}

int main() {
    int i, j;
    tint H, B, s, e, m, h;
    char r[MAXN], t[MAXN], rmt[MAXN];
    pt bottom, top, glass, tmp;

    while (cin >> H >> B && (H!=0 && B!=0)) {
        cin >> r;
        cin >> t;
    
        j = 0; rmt[j++] = '(';
        for (i=0; r[i]!='\0'; i++) rmt[j++] = r[i];
        rmt[j++] = ')'; rmt[j++] = '-'; rmt[j++] = '(';
        for (i=0; t[i]!='\0'; i++) rmt[j++] = t[i];
        rmt[j++] = ')';
    
        bottom = integrate(r, 0.0, B, (int)(TOTALSTEPS*B/H));
        top = integrate(r, B, H, (int)(TOTALSTEPS*(H-B)/H)) - integrate(rmt, B, H, (int)(TOTALSTEPS*(H-B)/H));
        glass = (bottom+top)*2.5;
    
        s = B; e = H;
        while (e-s > EPS) {
            m = (s+e)/2.0;
            int STEPS = (int)(TOTALSTEPS*(m-B)/H);
            tmp = integrate(rmt, B, m, STEPS) + glass;
            if (tmp.Mx/tmp.M > m) s = m;
            else e = m;
        }
        h = (s+e)/2.0;
        tmp = integrate(rmt, B, h, (int)(TOTALSTEPS*(h-B)/H))*pi;
        printf("Pour %.3lf litres / %.3lf cm of water.\n", tmp.M/1000.0, h-B);
    }

    return 0;
}

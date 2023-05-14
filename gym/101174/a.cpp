#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

typedef long double type;

struct point{
    type x, y;
    point () : x(0), y(0){}
    point (type x, type y) : x(x), y(y) {}

    point operator -() {return point(-x, -y);}
    point operator +(point p){return point(x + p.x, y + p.y);}
    point operator -(point p){return point(x - p.x, y - p.y);}
    
    point operator *(type k){return point(k * x, k * y);}
    point operator /(type k){return point(x/k, y/k);}
    
    type operator *(point p){return x * p.x + y * p.y;}

    type abs() {return sqrt(x * x + y * y);}
    point rotate(ld sin, ld cos) {return point(cos * x - sin * y, sin * x + cos * y);}
    point rotate(ld a) {return rotate(sin(a), cos(a));}
    point rotate(point p){return rotate(p.y / p.abs(), p.x / p.abs());}
};

int n, seg[50], last;
point fim;
ld d, tot, l2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seg[i];
        tot += seg[i];
        l2 += seg[i];
    }
    cin >> fim.x >> fim.y;
    d = fim.abs();
    // db(d _ tot);
    for(int i = 0; i < n; i++){
        if(tot < d){
            last = i - 1;
            break;
        }
        tot -= 2 * seg[i];
        l2 -= seg[i];
    }
    // db(last);
    point dir;
    if(d > 0) dir = (fim) / fim.abs();
    else dir = point(1, 0);
    if(n == 1){
        cout << (dir * seg[0]).x << " " << (dir * seg[0]).y << "\n";
        return 0;
    }
    if(last == -1){
        ld cur = 0;
        for(int i = 0; i < n; i++){
            cur += seg[i];
            cout << setprecision(15) << fixed << cur * dir.x << " " << cur * dir.y << "\n";
        }
    }
    else{
        ld cur = 0;
        for(int i = 0; i < last; i++){
            cur += seg[i];
            cout << setprecision(15) << fixed <<  - cur * dir.x << " " << - cur * dir.y << "\n";
        }

        //angle from the artic that rotates
        ld cos_u = (seg[last] * seg[last] + (d + cur) * (d + cur) - l2 * l2) / (2 * (d + cur) * seg[last]);
        ld ang = acos(cos_u);
        point artic = point(seg[last], 0);
        artic = artic.rotate(dir);
        artic = artic.rotate(ang);
        cout << (artic - dir * cur).x << " " << (artic - dir * cur).y << "\n";
        point current_point = artic - dir * cur;
        
        //angle for the rest
        point final_dir = (fim - current_point) / (fim - current_point).abs();
        cur = 0;
        for(int i = last + 1; i < n; i++){
            cur += seg[i];
            cout << setprecision(15) << fixed << (current_point + final_dir * cur).x << " " << (current_point + final_dir * cur).y << "\n";
        }
        ld dist = (fim - current_point).abs();
    }
    return 0;
}
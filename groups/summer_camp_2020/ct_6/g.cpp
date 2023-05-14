#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

struct point{
    int x,y,z;
};

void pr(point p, point q){
    cout << "(" << p.x << " " << p.y << " " << p.z << ") ";
    cout << "(" << q.x << " " << q.y << " " << q.z << ")\n";
}

point A, B, endA, endB;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A.x >> A.y >> A.z >> endA.x >> endA.y >> endA.z;
    cin >> B.x >> B.y >> B.z >> endB.x >> endB.y >> endB.z;
    pr(A,B);
    if(A.x == endA.x and B.x == endB.x and A.y == endA.y and B.y == endB.y and A.z == endA.z and B.z == endB.z) return 0;
    if(A.z == B.z){
        B.z++;
        pr(A,B);
    }
    while(endA.x!=A.x or endB.x!=B.x){
        if(A.x < endA.x) A.x++;
        else if (A.x > endA.x) A.x--;
        if(B.x < endB.x) B.x++;
        else if (B.x > endB.x) B.x--;
        pr(A,B);
    }
    while(endA.y!=A.y or endB.y!=B.y){
        if(A.y < endA.y) A.y++;
        else if (A.y > endA.y) A.y--;
        if(B.y < endB.y) B.y++;
        else if (B.y > endB.y) B.y--;
        pr(A,B);
    }
    if(A.x == B.x and A.y == B.y) B.y++, pr(A,B);
    while(endA.z!=A.z or endB.z!=B.z){
        if(A.z < endA.z) A.z++;
        else if (A.z > endA.z) A.z--;
        if(B.z < endB.z) B.z++;
        else if (B.z > endB.z) B.z--;
        pr(A,B);
    }
    if(B.y < endB.y) B.y++, pr(A,B);
    else if (B.y > endB.y) B.y--, pr(A,B);
    return 0;
}
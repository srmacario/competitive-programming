#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

map<string, set<char>> first;
int pos;
string s;

bool S();

bool expect(char c){
    if(c == s[pos]){
        pos++;
        return true;
    }
    return false;
}

bool A(){
    db("A");
    return (expect('}') or expect(','));
}


bool E(){
    db("E");
    bool check = true;
    if(first["A"].count(s[pos])){
        check = A();
        return check;
    }
    if(first["S"].count(s[pos])){
        check = S();
        return check;
    }
    return false;
}

bool L(){
    db("L");
    bool check = true;
    if(first["E"].count(s[pos])){
        check = E();
        if(!check) return false;
        check = expect(',');
        if(!check) return false;
        check = L();
        return check;
    }
    return true;
}

bool El(){
    db("El");
    bool check = true;
    if(first["L"].count(s[pos])){
        check = L();
        return check;
    }
    return true;
}

bool S(){
    db("S");
    bool check = true;
    check = expect('{');
    if(!check) return false;

    check = El();
    db(check);
    if(!check) return false;

    check = expect('}');
    return check;
}

string parser(){
    bool check = true;
    check = S();
    if(!check or !expect('$')) return "No Set";
    return "Set";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    first["A"] = {'}', ','};
    first["E"] = {'{', ',', '}'};
    first["S"] = {'{'};
    first["L"] = first["E"];
    first["El"] = first["L"];
    first["S_"] = first["S"];

    for(int i = 1; i <= t; i++){
        cin >> s;
        s += '$';
        cout << "Word #" << i << ": ";
        cout << parser() << "\n";
    }
    return 0;
}

/*
    Grammar
        S' -> S$
        S -> { El }
        El -> L
        El -> e
        L -> E L
        L -> e
        E -> A
        E -> S
        A -> }
        A -> ,

        First(A) =                          '{', ','
        First(E) = First(A) u First(S) =    '{', ',', '}'
        First(S) =                          '{'
        First(L) = First(E) =               '{', ',', '}'
        First(El) = First(L) =              '{', ',', '}'
        First(S') = First(S) =              '{'
*/
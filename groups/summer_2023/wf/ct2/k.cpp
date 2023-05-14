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

int x = -1;

string max(string a, string b){
    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] > b[i]) return a;
        if(a[i] < b[i]) return b;
    }
    return a;
}

string sub(string a, string b){
    //db(a _ b);
    for(int i = a.size(); i < max(a.size(), b.size()); i++) a += '0';
    for(int i = b.size(); i < max(a.size(), b.size()); i++) b += '0';
    int carry = 0;
    string c;
    for(int i = 0; i < a.size(); i++){
        a[i] -= carry;
        if(a[i] >= b[i]){
            c += (a[i] - '0') - (b[i] - '0') + '0';
            carry = 0;
        }
        else{
            c += 10 + (a[i] - '0') - (b[i] - '0') + '0';
            carry = 1;
        }
    }
    while(c.back() == '0') c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}

string add(string a, string b){
    string c;
    for(int i = a.size(); i < max(a.size(), b.size()); i++) a += '0';
    for(int i = b.size(); i < max(a.size(), b.size()); i++) b += '0';
    int carry = 0;
    for(int i = 0; i < a.size(); i++){
        c += ((a[i] - '0') + (b[i] - '0') + carry) % 10 + '0';
        if(((a[i] - '0') + (b[i] - '0') + carry) > 9){
            carry = 1;
            x = i;
        }
        else carry = 0;
    }
    if(carry) c += carry + '0';
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b, c;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    c = add(a, b);
    if(x == -1){
        cout << "0\n";
        return 0;
    }
    string d;
    for(int i = 0; i <= x; i++) d += '0';
    d += '1';
    cout << sub(d, max(a.substr(0, x + 1), b.substr(0, x + 1))) << "\n";
    return 0;
}
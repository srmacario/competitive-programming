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
const int N = 2e3+5;

int n, m;
bitset<N> eq[N], ones[N];
int r[N], ans[N];

int a = INT_MAX;

bool gauss_xor(int n, int m){
	for(int i = 0; i < m; i++)
		ans[i] = true;
	int lid[N] = {0}; // id + 1 of last element present in i-th line of final matrix
	int l = 0;
	for(int i = m - 1; i >= 0; i--){
		for(int j = l; j < n; j++)
			if(eq[j][i]){ // pivot
				swap(eq[l], eq[j]);
				swap(r[l], r[j]);
			}
		if(l == n || !eq[l][i])
			continue;
		lid[l] = i + 1;
		for(int j = l + 1; j < n; j++){ // eliminate column
			if(!eq[j][i])
				continue;
			
            eq[j] = (eq[l] & ones[i]) ^ eq[j];
			r[j] ^= r[l];
		}
		l++;
	}
	for(int i = n - 1; i >= 0; i--){ // solve triangular matrix
		for(int j = 0; j < lid[i + 1]; j++)
			r[i] ^= (eq[i][j] && ans[j]);
		// for lexicographically least just delete the for bellow
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            ones[i].set(j);
        }
    }
    cin >> n >> m;
    
    string s;
    getline(cin, s);
    for(int i = 0; i < n; i++){
        getline(cin, s);
        string current;
        int num;
        bool is_set = true;
        r[i] = 1;
        for(int j = 1; j <= s.size(); j++){
            if(s[j] == ')' or s[j] == ' '){
                if(current == "not"){
                    is_set ^= true;
                }
                else if(current != "or"){
                    num = stoi(current);
                    if(!is_set) r[i] ^= 1;

                    eq[i].flip(num - 1);
                    is_set = true;
                }
                current.clear();
                if(s[j] == ')') break;
                continue;
            }
            if(s[j] != 'x') current += s[j];
        }
    }
    if(gauss_xor(n, m)){
        for(int i = 0; i < m; i++) cout << (ans[i] ? "T" : "F");
        cout << "\n";
    }
    else cout << "impossible\n";
    return 0;
}
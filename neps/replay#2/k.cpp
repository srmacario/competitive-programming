#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 505, M = 2e4+5;

int n, l, dp[N][M];
string s[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		dp[i][l] = INF;
	}
	for(int i = 1; i < n; i++){
		for(int j = l-1; j >= 0; j--){
			if(s[i-1][j] < s[i][j]) dp[i][j] = j;
			else if(s[i][j] == s[i-1][j]) dp[i][j] = dp[i][j+1];
			else dp[i][j] = INF;
		}
	}
	piii ans = {INF, {0,0}};
	for(int j = 0; j < l; j++){
		piii cur = {0,{0,0}};
		for(int i = 1; i < n; i++){
			piii tmp = {dp[i][j] - j + 1,{j, dp[i][j]}};
			cur = max(tmp, cur);
		}
		ans = min(cur, ans);
	}
	cout << ans.nd.st + 1 << " " << ans.nd.nd + 1<< "\n";
    return 0;
}
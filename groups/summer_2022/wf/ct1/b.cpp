#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const ll MOD = 1e9 + 9;
const int N = 4e4 + 5;

ull h[N], p[N], pr = 1777771;

void build(string &s){
	p[0] = 1, p[1] = pr;
	for(int i = 1; i <= s.size(); i++){
		h[i] = ((p[1] * h[i - 1]) % MOD + (s[i - 1] - 'a' + 1)) % MOD;
		p[i] = (p[1] * p[i - 1]) % MOD;
	}
}

ull fhash(int l, int r){
	return (h[r] - ((h[l - 1] * p[r - l + 1]) % MOD) + MOD) % MOD;
}

string s;
int n;

pii test(int t){
	unordered_map<ull, int> mp;
	pii ans = {0, 0};
	for(int i = 1; i + t - 1 <= s.size(); i++){
		ull v = fhash(i, i + t - 1);
		mp[v]++;
		if(mp[v] >= n)
			ans = {mp[v], i};
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while(n){
		cin >> s;
		build(s);
		int l = 1, r = s.size();
		pii t;
		while(l < r){
			int mid = (l + r + 1) / 2;
			t = test(mid);
			if(t.st < n)
				r = mid - 1;
			else
				l = mid;
		}
		t = test(l);
		if(t.st < n)
			cout << "none\n";
		else
			cout << l << " " << t.nd - 1 << "\n";
		cin >> n;
	} 
	return 0;
}
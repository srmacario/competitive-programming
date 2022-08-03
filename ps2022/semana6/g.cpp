#include <bits/stdc++.h>

using namespace std;
const int N = 30;
int t;
string a, b;
int par[N], sz[N];
vector<int> maximal;

int find(int a) {
	return par[a] == a ? a : par[a] = find(par[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a==b)
		return;
	if(sz[a] < sz[b])
		swap(a,b);
	sz[a] += sz[b];
	//cout << sz[a] << " " << sz[b] << "\n";
	par[b] = a;
	
}

pair<int, int> conv(string a) {
	pair<int, int> p;
	p.first = a[0] - 'A' + 1;
	p.second = a[1] - 'A' + 1;
	
	return p;
}

int main () {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		for(int i = 1; i < N; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		cin >> a;
		pair<int, int> eq = conv(a);
		int n = eq.first;
		//cout << n << "\n";
		cin.ignore();
		while(getline(cin, b)) {
			if(b.length() == 0)  {
				break;
			}
			pair<int, int> num = conv(b);
			//cout << num.first << " " << num.second << "\n";
			unite(num.first, num.second);
		}
		
		int count = 0;
		for(int i = 1; i <=n; i++) {
			if(find(maximal.begin(), maximal.end(), par[i]) == maximal.end()) {
				maximal.push_back(par[i]);
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
	
}
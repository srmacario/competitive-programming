#include<bits/stdc++.h>
using namespace std;

const int N = 30;

int n, t, k, x, vis[N], b[N];
string s, ss[N][N];
vector<int> adj[N];

bool match(int u) {
  if (vis[u] == x) return 0;
  vis[u] = x;
  for (int v : adj[u])
    if (!b[v] or match(b[v])) return b[v]=u;
  return 0;
}

int main(){
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> n;
        memset(ss, 0, sizeof(ss));
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			b[i] = 0;
		}
        x = 0;
		for(int i = 1; i <= n; i++){
			cin >> k;
			while(k--){
				cin >> s;
				if(islower(s[0]))
					s[0] += 'A' - 'a';
				for(int j = 1; j < s.size(); j++)
					if(!islower(s[j]))
						s[j] += 'a' - 'A';
				ss[i][s[0] - 'A' + 1] = s;
				adj[s[0] - 'A' + 1].push_back(i);
			}
		}
		for (int i = 1; i <= n; ++i) ++x, match(i);
		cout << "Case #" << tt <<":\n";
		for(int i = 1; i <= n; i++)
			cout << ss[b[i]][i] << '\n';
	}
	return 0;
}
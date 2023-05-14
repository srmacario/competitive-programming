#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
long long bit[N];
long long n, b, q, l, r;
char op;

void update(long long x, int pos) {
	while(pos <=n) {
		bit[pos] += x;
		pos += pos&(-pos);
	}
}

long long query(int pos) {
	long long r = 0;
	while(pos) {
		r+= bit[pos];
		pos -= pos&(-pos);
	}
	return r;
}

long long rangesum(int l, int r) {
	return query(r) - (l? query(l-1) : 0);
}

int main () {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <=n; i++) {
		cin >> b;
		update(b, i);
	}
	cin >> q;
	while(q--) {
		cin >> op >> l >> r;
		if(op == 'q') {
			cout << rangesum(l, r) << "\n";
		}
		else {
			update(r, l);
		}
	}
	return 0;
}
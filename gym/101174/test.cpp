#include <bits/stdc++.h>

using namespace std;

int main() {
	long n, p, q, c;
	vector<long> price;
	vector<long> coin;

	cin >> n;
	for (long i = 0; i < n; i++) {
		cin >> p;
		price.push_back(p);
	}
    sort(price.begin(), price.end());
	cin >> q;
	
	for (long i = 0; i < q; i++) {
		cin >> c;
		coin.push_back(c);
	}
	
	long a, index;

    for (long i = 0; i < q; i++) {
        auto it = upper_bound(price.begin(), price.end(), coin[i]);
        index = (it - price.begin());
        cout << index << '\n';
    }
	
	return 0;
}
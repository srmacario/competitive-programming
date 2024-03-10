#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100 << 6;

string g[2];

pii dp[2];
int s[2][500], n, comb[5] = {0, 7, 13, 14, 11};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "250  26\n"; 
    for(int i = 0; i < 250; i++) cout << (1'000'000'000 - i) << " ";
    return 0;
}

/*
0 1 2
0 1 3
1 2 3
0 2 3

00 -> xx
00    x0



*/
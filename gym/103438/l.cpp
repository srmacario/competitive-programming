#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, l1[2], l2[2];
char c[2];
int cnt[3];
string s;

bool test_zero(){
    return (cnt[0] == n) and (cnt[1] == n) and (cnt[2] == n);
}

bool test_one(){
    map<char, int> over_char;
    map<char, int> cur_cnt;
    char left_char = 'A';
    vector<char> ok_char;
    //look for chars over n
    for(int i = 0; i < 3; i++){
        if(cnt[i] >= n) over_char[char('A' + i)] = cnt[i] - n, ok_char.push_back(char('A' + i));
        else left_char = char('A' + i);
    }
    if(over_char.size() < 2) return false;
    int l = 0, r = 0;
    for(l = 0, r = 0; r < 3 * n; r++){
        if(s[r] == left_char) continue;
        cur_cnt[s[r]]++;
        while(l <= r and ((cur_cnt[ok_char[0]] > over_char[ok_char[0]]) or (cur_cnt[ok_char[1]] > over_char[ok_char[1]]))){
            cur_cnt[s[l++]]--;
        }
        if(l <= r and (cur_cnt[ok_char[0]] == over_char[ok_char[0]]) and (cur_cnt[ok_char[1]] == over_char[ok_char[1]])){
            l1[0] = l, l2[0] = r, c[0] = left_char;
            return true;
        }
    }
    return false;
}

bool test_two(){
    int cur_cnt[3] = {0};
    for(int i = 0; i < 3 * n; i++){
        cur_cnt[s[i] - 'A']++;
        if(cur_cnt[s[i] - 'A'] == n){
            l1[0] = i + 1, l2[0] = i + n - cur_cnt[(s[i] - 'A' + 1) % 3], c[0] = char('A' + ((s[i] - 'A' + 1) % 3));
            l1[1] = i + n - cur_cnt[(s[i] - 'A' + 1) % 3] + 1, l2[1] = 3 * n - 1, c[1] = char('A' + ((s[i] - 'A' + 2) % 3));
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(auto ch : s) cnt[ch - 'A']++;
    if(test_zero()){
        cout << "0\n";
    }
    else if(test_one()){
        cout << "1\n";
        cout << l1[0] + 1 << " " << l2[0] + 1 << " "  << c[0] << "\n";
    }
    else{
        if(test_two() == false) return 1;
        cout << "2\n";
        cout << l1[0] + 1 << " " << l2[0] + 1 << " "  << c[0] << "\n";
        cout << l1[1] + 1 << " " << l2[1] + 1 << " "  << c[1] << "\n";
    }
    return 0;
}
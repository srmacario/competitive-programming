#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 1e5+5, M = 1e6+5;

ll n, s, w[N], v[N], wknap[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // memset
    for(int i=0;i<M;i++) wknap[i] = LINF;
    // input
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    //itera por cada item e vai marcando quais valores a minha bolsa consegue atingir usando aquele item
    for(int i=0;i<n;i++){
        //percorre possiveis valores
        for(int j=N;j>=0;j--){
            //atualiza o valor j + v[i] com o minimo entre o peso atual e o peso do valor j + v[i]
            wknap[j + v[i]] = min(w[i] + wknap[j], wknap[j+v[i]]);
            //atualiza o peso de v[i] com o minimo entre o atual e o peso de i (w[i])
            if(j == v[i]) wknap[v[i]] = min(w[i],wknap[v[i]]);
            //WA: if(wknap[j] == LINF and j == v[i]) wknap[v[i]] = w[i];
            //essa etapa tem que ser depois pois pode atualizar o peso de v[i] antes de atualizar o peso da soma 
        }
    }
    //procura o maior cara com peso compativel com a mochila
    for(int j=N;j>=0;j--){
        if(wknap[j] <= s){
            cout << j << "\n";
            break;
        }
    }
    return 0;
}
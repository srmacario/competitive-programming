#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

const int N = 1000;

int n;
set <string> s[N];
set <char> forb;
map <int,string> dic;
string x;

void add(int id){
    int cnt = 0, fst = 0;
    while(cnt < x.size()){
        string aux;
        while(!forb.count(x[cnt]) and cnt < x.size()){
            if(x[cnt] - 'A' < 26 and x[cnt] - 'A' >= 0 and fst) x[cnt] = x[cnt] - 'A' + 'a';
            aux += x[cnt++];
        }
        if(fst){
            s[id].insert(aux);
        }
        else{
            dic[id] = aux;
            fst++;
        }
        cnt++;
    }
}

string search(){
    int cnt = 0;
    while(cnt < x.size()){
        string aux;
        while(!forb.count(x[cnt]) and cnt < x.size()){
            if(x[cnt] - 'A' < 26 and x[cnt] - 'A' >=0) x[cnt] = x[cnt] - 'A' + 'a';
            aux += x[cnt++];
        }
        for(int i=0;i<n;i++){
            if(s[i].count(aux)) return dic[i];
        }
        while(forb.count(x[cnt])) cnt++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    forb.insert(' ');
    forb.insert(',');
    forb.insert('.');
    forb.insert('!');
    forb.insert(';');
    forb.insert('?');
    forb.insert('(');
    forb.insert(')');
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,x);
        add(i);
    }
    getline(cin,x);
    while(getline(cin,x)){
        string ans = search();
        cout << ans << "\n";
    }
    return 0;
}

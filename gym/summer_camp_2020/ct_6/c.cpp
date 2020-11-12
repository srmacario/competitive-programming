#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long

int red,n;
ll ans;
vi c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        if(x == "red") red++;
        else{
            if(x == "yellow") c.pb(2);
            if(x == "green") c.pb(3);
            if(x == "brown") c.pb(4);
            if(x == "blue") c.pb(5);
            if(x == "pink") c.pb(6);
            if(x == "black") c.pb(7);
        }
    }
    sort(c.begin(),c.end());
    while(c.size() + red > 0){
        if(c.size()){
            ans+=c[c.size()-1];
            if(red) ans++,red--;
            else c.pop_back();
        }
        else ans+= 1, red=0;
    }
    cout << ans << "\n";
    return 0;
}
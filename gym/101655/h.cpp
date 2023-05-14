#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back

const int N = 1000;

ll poss(ll k, ll c){
    if(c){
        return 10 - k - 1;
    }
    else return k + !(k%2); 
}

int t;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> t;
    while(t--){
        bool ok = true;
        ll ans = 1;
        string s;
        vi c;
        cin >> s;
        int n = s.size();
        c.resize(n);
        c[0] = c[n-1] = 0;
        if(s[0] - s[n-1] > 1 or s[n-1] - s[0] > 0){
            cout << "0\n";
            ok = false;
            continue;
        }
        else if(s[0] - s[n-1]) c[1] = c[n-2] = 1;
        else c[1] = c[n-2] = 0;
        for(int i=1;i<n/2;i++){
            char news = s[n-i-1] - c[n-i];
            if(s[i] - news > 1 or news - s[i] > 0){
                ans = 0;
            }
            else if(s[i] - news) c[i+1] = c[n-i-2] = 1;
            else c[i+1] = c[n-i-2] = 0;
        }
        int mid = s[(n)/2] - '0' + c[(n)/2 + 1];
        if(n%2 and mid%2){
            ans = 0;
        }
        ll num = 0;
        num = s[n-1] - '0';
        ans *= poss(num,0);
        for(int i=n-2;i>n/2;i--){
            num = s[i] - c[i+1] - '0';
            ans *= poss(num, c[i]);
        }
        if(s[0] == '1' and ok){
            c.clear();
            ll ans2 = 1;
            c[1] = c[n-2] = 1;
            c[0] = c[n-1] = 1;
            if(s[0] - s[n-1] + c[1] > 1 or s[n-1] - s[0] - c[1] > 0){
                ans2 = 0;
            }
            for(int i=1;i<n/2;i++){
                char news = s[n-i-1] - c[n-i];
                //cout << news << " " << s[i] << "\n";
                if(s[i] - c[i] - news > 1 or news - s[i] + c[i] > 0){
                    ans2 = 0;
                    break;
                }
                else if(s[i] - c[i] - news) c[i+1] = c[n-i-2] = 1;
                else c[i+1] = c[n-i-2] = 0;
            }
            int mid = s[(n)/2 + 1] - '0' + c[(n)/2-1];
            if(n%2 and mid%2){
                ans2 = 0;
            }
            ll num = 0;
            num = s[n-1] - '0';
            ans2 *= poss(num,0);
            for(int i=n-2;i>=n/2;i--){
                num = s[i] - c[i+1] - '0';
                ans2 *= poss(num, c[i]);
            }
            //cout << ans2 << "\n";
            ans += ans2;
        }
        if(s == "11") ans--;
        cout << ans  << "\n";
    }
    return 0;
}

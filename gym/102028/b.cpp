#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll ha, hb, aa, ab;
        cin >> ha >> hb >> aa >> ab;
        ll sum = 0, i;
        ll d1 = 0, d2 = 0, d3 = 0;
        string s1, s2, s3;
        for(i = 1; sum < ha; i++){
            s1 += 'A';
            sum += i;
            d1 += (aa + ab);
        }
        sum -= ha;
        if(sum > 0)
            s1[sum - 1] = 'B';
        for(; sum < hb; i++){
            d1 += ab;
            s1 += 'B';
            sum += i;
        }
        sum = 0;
        for(i = 1; sum < hb; i++){
            s2 += 'B';
            sum += i;
            d2 += (aa + ab);
        }
        sum -= hb;
        for(ll j = 1, sumh = sum; sumh; j++){
            if(sumh - j <= j){
                s2[sumh - 1] = 'A';
                sumh = 0;
            }
            else{
                sumh -= j;
                s2[j - 1] = 'A';
            }
        }
        for(; sum < ha; i++){
            d2 += aa;
            s2 += 'A';
            sum += i;
        }
        sum = 0;
        for(i = 1; sum < ha; i++){
            s3 += 'A';
            sum += i;
            d3 += (aa + ab);
        }
        sum = 0;
        for(; sum < hb; i++){
            d3 += ab;
            s3 += 'B';
            sum += i;
        }
        pair<ll, string> ans = min({make_pair(d1, s1), make_pair(d2, s2), make_pair(d3, s3)});
        cout << ans.st << " " << ans.nd << '\n';
    }
    return 0;
}
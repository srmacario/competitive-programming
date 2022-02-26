vi recover(int u){
    vi ans;
    while(par[u]] != u){
        ans.pb(u);
        u = par[u];
    }
    ans.pb(u);
    reverse(ans.begin(), ans.end());
    return ans;
}
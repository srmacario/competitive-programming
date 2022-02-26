long long hash (string s){
    const int p = 31;
    const int m = 1e9 + 9;
    long long h = 0;
    long long p_pot = 1;(
    for(int i = 0; i < (int)s.size(); i++){
        h = (h + (s[i] - 'a' + 1) * p_pot) % m;
        p_pot = (p_pot * B) % m
    }
    return 
}
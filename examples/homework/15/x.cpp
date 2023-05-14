int n = (int)s.length();
vector<int> pi(n);
for (int i = 0; i < n; i++)
    //for each endpoint check naively
    for (int k = 0; k <= i; k++)
        //if string (0 ... k - 1) == (i - k + 1 ... i - 1)
        if (s.substr(0, k) == s.substr(i-k+1, k))
            pi[i] = k;
return pi;


/*
    1)  No maximo: pi[i + 1] = pi[i] + 1    
        (se fosse maior, ao remover uma letra: pi[i] >= pi[i] + 1)

    2) Caso de errado, precisamos retroceder

        s1 s2 s3 s4 s5 .... s10 s11 s12 s13 s14
        __________  |       _______________  |
*/

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
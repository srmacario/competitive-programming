vi rabin_karp(string s, string t){
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = (s.size());
    vector<ll> p_pot(max(S, T));

    //precalcular as potencias
    p_pot[0] = 1;
    for(int i = 1; i < (int)p_pot.size(); i++) p_pot[i] = (p_pow[i-1] * p) % m;
    
    //calcular o hash pra cada prefixo de t
    vector <ll> h(T + 1, 0);
    for(int i = 0; i < T; i++) h[i+1] = (h[i] + (t[i] - 'a' + 1)*p_pot[i]) % m;

    //calcular o hash para o padrão s que desejo procurar

    for(int i = 0; i < S; i++) h_s = (h_s + (s[i] - 'a' + 1) * p_pot[i]) % m;

    //vetor que guarda as posicoes das ocorrencias
    vi occ;

    //procura as posicoes pra dar o padrão s dar match dentro da string t
    for(int i = 0; i + S - 1 < T; i++){
        ll cur_h = (h[i+S] - h[i] + m) % m;
        //lembrar que a substring [i , i + S - 1], está shiftada de i posições
        if(cur_h == h_s * p_pot[i] % m)
            occ.pb(i);  
    }
    return occ;
}
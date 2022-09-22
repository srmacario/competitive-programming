#include <bits/stdc++.h>

using namespace std;

map<pair<set<string>, pair<int, vector<string>>>, pair<int, int>> dp, all_dp;

pair<int, int> calc(set<string> dictionary, set<char> letter, string winner, int current_player, vector<string> caminho){
    if(dp.count({dictionary, {current_player, caminho}})){
        // all_dp[{dictionary, {current_player, caminho}}].first += dp[{dictionary, {current_player, caminho}}].first;
        // all_dp[{dictionary, {current_player, caminho}}].second += dp[{dictionary, {current_player, caminho}}].second;
        return dp[{dictionary, {current_player, caminho}}];
    }

    //chutando a letra ch
    if(dictionary.size() == 1){
        if(current_player == 0) dp[{dictionary, {current_player, caminho}}] = {1, 0};
        else dp[{dictionary, {current_player, caminho}}] = {0, 1};

        // all_dp[{dictionary, {current_player, caminho}}].first += dp[{dictionary, {current_player, caminho}}].first;
        // all_dp[{dictionary, {current_player, caminho}}].second += dp[{dictionary, {current_player, caminho}}].second;
        return dp[{dictionary, {current_player, caminho}}];
    }

    pair<int, int> resp = {0, 0};
    for(auto ch : letter){
        set<string> next_dictionary = dictionary, rem;
        set<char> next_letter = letter, rem_letter;
        //checar posicoes validas
        set<int> posicoes_validas;
        for(int i = 0; i < winner.size(); i++){
            if(ch == winner[i]){
                posicoes_validas.insert(i);
            }
        }

        //excluir palavras que nao possuem a letra ou possuem a letra em uma posicao invalida
        for(auto word : dictionary){
            //achou a letra em algum canto, remove palavras que nao tem aquela letra
            if(posicoes_validas.size()){
                if(word.find(ch) == string::npos){
                    rem.insert(word);
                    continue;    
                }
            
                for(int i = 0; i < word.size(); i++){
                    if(posicoes_validas.count(i) and word[i] != ch){
                        rem.insert(word);
                        break;
                    }
                    if(word[i] == ch and posicoes_validas.count(i) == 0){
                        rem.insert(word);
                        break;
                    }
                }
            }
            //nao achou a letra, remove palavras que tem aquela letra
            else{
                if(word.find(ch) != string::npos){
                    rem.insert(word);
                    continue;    
                }
            }
        }
        for(auto word : rem) next_dictionary.erase(word);

        // excluir letras invalidas
        next_letter.erase(ch);
        for(auto ch2 : next_letter){
            bool letra_existe = false;
            for(auto word : next_dictionary){
                if(word.find(ch2) != string::npos) letra_existe = true;
            }
            if(letra_existe == false) rem_letter.insert(ch2);
        }
        for(auto ch2 : rem_letter) next_letter.erase(ch2);
        
        //chamar a proxima recursao
        vector<string> novo_caminho = caminho;
        novo_caminho[current_player].push_back(ch);
        novo_caminho[current_player ^ 1].push_back('_');
        pair<int, int> next_resp;
        if(posicoes_validas.size() == 0){
            next_resp = calc(next_dictionary, next_letter, winner, current_player ^ 1, novo_caminho);
        }
        else{
            next_resp = calc(next_dictionary, next_letter, winner, current_player, novo_caminho);
        }
        long double prob = 0, next_prob = 0;
        
        // if(current_player == 0){
        //     long double cur_den = resp.first + resp.second, nxt_den = next_resp.first + next_resp.second;
        //     long double cur_num = resp.first, nxt_num = next_resp.first;
        //     if(resp.first + resp.second != 0) prob = cur_num / cur_den;
        //     next_prob = nxt_num / nxt_den;
        //     if(next_prob >= prob) resp = next_resp;
        //     if(caminho[0].empty()) cout << winner << ": " << ch << " " << next_prob << "\n";
        // }
        // else{
        //     long double cur_den = resp.first + resp.second, nxt_den = next_resp.first + next_resp.second;
        //     long double cur_num = resp.second, nxt_num = next_resp.second;
        //     if(resp.first + resp.second != 0) prob = cur_num / cur_den;
        //     next_prob = nxt_num / nxt_den;
        //     if(next_prob >= prob) resp = next_resp;
        //     if(caminho[0].empty()) cout << winner << ": " << ch << " " << next_prob << "\n"; 
        // }

    }
    dp[{dictionary, {current_player, caminho}}] = resp;
    // all_dp[{dictionary, {current_player, caminho}}].first += dp[{dictionary, {current_player, caminho}}].first;
    // all_dp[{dictionary, {current_player, caminho}}].second += dp[{dictionary, {current_player, caminho}}].second;
    return dp[{dictionary, {current_player, caminho}}];
}

//afh, akt, abd
//afh, akt, abd

int main(){
    // set<string> dictionary = {"afh" , "akt" , "ffl", "utf", "abd", "tyh"};
    set<string> dictionary = {"afh" , "akf" , "abd"};
    set<char> letter;
    for(auto word : dictionary){
        for(auto ch : word){
            letter.insert(ch);
        }
    }
    // string caminho;
    pair<int, int> resp;
    resp = calc(dictionary, letter, "afh", 0, {"", ""});
    cout << resp.first << " " << resp.second << "\n";
    // cout << all_dp[{dictionary, {0, {"", ""}}}].first << " " << all_dp[{dictionary, {0, {"", ""}}}].second << "\n";
    dp.clear();
    
    resp = calc(dictionary, letter, "akf", 0, {"", ""});
    cout << resp.first << " " << resp.second << "\n";
    // cout << all_dp[{dictionary, {0, {"", ""}}}].first << " " << all_dp[{dictionary, {0, {"", ""}}}].second << "\n";
    dp.clear();
    
    resp = calc(dictionary, letter, "abd", 0, {"", ""});
    cout << resp.first << " " << resp.second << "\n";
    // cout << all_dp[{dictionary, {0, {"", ""}}}].first << " " << all_dp[{dictionary, {0, {"", ""}}}].second << "\n";
    dp.clear();
    map<char, pair<int, int>> ans;
    for(auto d : all_dp){
        if(d.first.second.second[0].size() == 1){
            // cout << d.first.second.second[0][0] << " " << d.second.first << " " << d.second.second << "\n";
            ans[d.first.second.second[0][0]].first += d.second.first;
            ans[d.first.second.second[0][0]].second += d.second.second;
        } 
    }
    for(auto a : ans) cout << a.first << " " << a.second.first << " " << a.second.second << "\n";
    // resp = calc(dictionary, letter, "utf", 0, {"", ""}, 3);
    // cout << resp.first << " " << resp.second << "\n";
    
    // resp = calc(dictionary, letter, "ffl", 0, {"", ""}, 3);
    // cout << resp.first << " " << resp.second << "\n";
    
    // resp = calc(dictionary, letter, "tyh", 0, {"", ""}, 3);
    // cout << resp.first << " " << resp.second << "\n";
    return 0;
}
#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

class WeirdRooks{
public:
    //set<pair<int, int>> ans;
    int mx[10], ans[10][100], rook_grid[10][10], special_grid[10][10], cnt = 0;
    vector<int> cols;

    void add_rook(int r, int c, int k){
        for(int i = 0; i < cols.size(); i++){
            if(cols[i] <= c) continue;
            rook_grid[i][c] += k;
        }
        for(int i = 0; i < cols[r]; i++){
            rook_grid[r][i] += k;
        }
        rook_grid[r][c] -= k;
    }

    void add_special(int r, int c, int k){
        for(int i = 0; i <= r; i++){
            if(cols[i] <= c) continue;
            special_grid[i][c] += k;
            if(i != r){
                if(special_grid[i][c] == k) cnt--;
                if(special_grid[i][c] == 0) cnt++;
            }
        }
        for(int i = 0; i <= c; i++){
            special_grid[r][i] += k;
            if(i != c){
                if(special_grid[r][i] == k) cnt--;
                if(special_grid[r][i] == 0) cnt++;
            }
        }
        special_grid[r][c] -= k;
        if(special_grid[r][c] == k) cnt--;
        if(special_grid[r][c] == 0) cnt++;
    }

    void bt(int r, int k, int bit, int need){
        if(cols.size() - r + bit < need) return;
        if(r == cols.size()){
            ans[bit][cnt] = 1;
            mx[bit] = max(mx[bit], cnt);
            return;
        }
        if((1 << r) & k){
            for(int i = 0; i < cols[r]; i++){
                if(!rook_grid[r][i]){
                    add_rook(r, i, 1);
                    add_special(r, i, 1);
                    bt(r + 1, k, bit + 1, need);
                    add_rook(r, i, -1);
                    add_special(r, i, -1);
                }
            }
        }
        else bt(r + 1, k, bit, need);
    }

    void calc(){
        int k = (1 << (cols.size()));
        for(int i = 0; i < cols.size(); i++) cnt += cols[i];
        int i = 1;
        for(int i = 0; i < k; i++){
            int need = 0;
            memset(rook_grid, 0, sizeof(rook_grid));
            memset(special_grid, 0, sizeof(special_grid));
            for(int j = 1; (1 << j) <= i; j++){
                if((1 << j) & i) need++;
            }
            bt(0, i, 0, need);
        }
    }

    string describe(vector<int> cols){
        this -> cols = cols;
        memset(mx, 0, sizeof(mx));
        memset(rook_grid, 0, sizeof(rook_grid));
        memset(special_grid, 0, sizeof(special_grid));    
        memset(ans, 0, sizeof(ans));
        calc();
        string resp;
        for(int i = 0; i <= cols.size(); i++){
            for(int j = 0; j <= mx[i]; j++){
                if(ans[i][j]){
                    string tmp;
                    tmp += to_string(i);
                    tmp += ",";
                    tmp += to_string(j);
                    resp += tmp + " ";
                }
            }
        }
        resp.pop_back();
        return resp;
    }
};

int main(){
    WeirdRooks wr;
    vector<int> test = {3, 3, 3};
    cout << wr.describe(test) << "\n";
    return 0;
}
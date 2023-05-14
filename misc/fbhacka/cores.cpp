#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strokesRequired' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY picture as parameter.
 */

#define st first
#define nd second
const int N = 1e5+5;

pair<int, int> dist[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int vis[N];

int id(int i, int j, int r, int c){
    return i*c + j;
}

void dfs(int i, int j, int r, int c, const vector<string> &picture){
    if(i < 0 or i >= r or j < 0 or j >= c) return;
    vis[id(i,j,r,c)] = 1;
    for(auto p : dist){
        if(i+p.st < 0 or i+p.st >= r or j+p.nd < 0 or j+p.nd >= c) continue;
        if(!vis[id(i+p.st, j+p.nd, r, c)] and picture[i][j] == picture[i+p.st][j+p.nd]){
            dfs(i+p.st, j+p.nd, r, c, picture);
        }
    }
}

int strokesRequired(vector<string> picture) {
    int cnt = 0, r = (int)picture.size(), c = (int)picture[0].size();
    for(int i = 0; i < (int)picture.size(); i++){
        for(int j = 0; j < (int)picture[i].size(); j++){
            if(!vis[id(i, j, r, c)]){
                dfs(i, j, r, c, picture);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string picture_count_temp;
    getline(cin, picture_count_temp);

    int picture_count = stoi(ltrim(rtrim(picture_count_temp)));

    vector<string> picture(picture_count);

    for (int i = 0; i < picture_count; i++) {
        string picture_item;
        getline(cin, picture_item);

        picture[i] = picture_item;
    }

    int result = strokesRequired(picture);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
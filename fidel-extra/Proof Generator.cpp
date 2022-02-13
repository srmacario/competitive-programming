#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstring>
using namespace std;

#define FORMULA(c) ( (c)!='-' && ( (c)<'0' || (c)>'9' ) )
#define SUM(c) ( (c)=='+' )

vector<string> input;
int POS_COUNT, POS, CUR;
bool v[26];

long long formula_count(bool change) {
    long long RES;

    if (input[CUR][POS_COUNT] == '~') {
        POS_COUNT++;
        return formula_count(!change);
    }

    if (input[CUR][POS_COUNT] >= 'a' && input[CUR][POS_COUNT] <= 'z') {
        if (change^v[input[CUR][POS_COUNT++]-'a']) RES = 1LL;
        else RES = 0LL;
        return RES;
    }

    POS_COUNT++; bool sum = change^SUM(input[CUR][POS_COUNT++]);
    if (sum) {
        RES = 0LL;
        while (input[CUR][POS_COUNT] != ')') RES += formula_count(change);
    } else {
        RES = 1LL;
        while (input[CUR][POS_COUNT] != ')') RES *= formula_count(change);
    }
    POS_COUNT++;
    return RES;
}

string formula_get(long long k, bool change) {
    string res = "";

    if (input[CUR][POS] == '~') {
        POS++;
        return formula_get(k, !change);
    }

    if (input[CUR][POS] >= 'a' && input[CUR][POS] <= 'z') {
        if (change) res += "~";
        res += input[CUR][POS++];
        return res;
    }

    POS++; bool sum = change^SUM(input[CUR][POS++]);
    if (sum) {
        while (input[CUR][POS] != ')') {
            POS_COUNT = POS;
            long long cant = formula_count(change);
            if (k >= 0 && k < cant) res = formula_get(k, change);
            else POS = POS_COUNT;
            k -= cant;
        }
    } else {
        long long tmp = 1LL; POS_COUNT = POS;
        while (input[CUR][POS_COUNT] != ')') tmp *= formula_count(change);

        while (input[CUR][POS] != ')') {
            POS_COUNT = POS;
            tmp /= formula_count(change);
            res += formula_get(k/tmp, change);
            k %= tmp;
        }
    }
    POS++;
    return res;
}

int main() {
    int i, j;
    string tmp;
    long long cant, cur, jump;

    cin >> tmp; input.push_back(tmp);
    while (cin >> tmp) {
        if (FORMULA(tmp[0]) && FORMULA(input.back()[0])) input.back() += tmp;
        else input.push_back(tmp);
    }

    CUR = 0;
    while (CUR < input.size()) {
        memset(v, false, sizeof(v));
        for (i=input[CUR].rfind("(")+1; input[CUR][i]!=')'; i++) v[input[CUR][i]-'a'] = true;

        POS_COUNT = 0;
        cant = formula_count(false);

        cur = -1LL; j = 1;
        do {
            sscanf(input[CUR + j++].c_str(), "%lld", &jump);
            if (cant == 0LL) continue;

            if (jump < 0) cur = (cur-jump)%cant;
            else if (jump > 0) {
                for (int k=1; k<=jump; k++) {
                    cur = (cur+1LL)%cant;
                    POS = 0;
                    string res = formula_get(cur, false);
                    if (res.size() > 2 || (res.size() == 2 && res[0] != '~')) cout << "(*" << res << ")" << endl;
                    else cout << res << endl;
                }
            }
        } while (jump != 0);
        CUR += j;
    }

    return 0;
}

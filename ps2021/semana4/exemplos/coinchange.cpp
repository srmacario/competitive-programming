/**********************************************************************************
* COIN CHANGE (MINIMUM AMOUNT OF COINS TO REACH A GIVEN TOTAL)                    *
* Description: Given a set of coins, each with a value, determine the minimum     *
* amount of such coins to include in a collection so that the total value is      *
* equal to a given one.                                                           *
* Usage: coin[amount]                                                             *
* Notation: v[i]:   values array                                                  *
*           n:      number of coins                                               *
*           amount: total amount of coins                                         *
**********************************************************************************/

const int N = 1e5+5; // Maximum number of items
const int A = 1e5+5; // Maximum value for 'amount'

int ans, n, amount, v[N], coin[A];

int main () {
    cl(v, 0); cl(coin, 63);
    coin[0] = 0;
    scanf("%d", &n);
    scanf("%d", &amount);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 0; i < n; i++)
        for (int j = v[i]; j < A; j++)
//      If there's a coin limitation, create a DECREASING j loop! Like this:
//      for (int j = A-1; j >= v[i]; j--)
            coin[j] = min(coin[j], 1+coin[j-v[i]]);
    ans = coin[amount];
}
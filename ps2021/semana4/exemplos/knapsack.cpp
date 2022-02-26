/**********************************************************************************
* KNAPSACK PROBLEM (ITEMS IN A BACKPACK)                                          *
* Description: Given a set of items, each with a weight and a value, determine    *
* the number of each item to include in a collection so that the total weight is  *
* less than or equal to a given limit and the total value is as large as          *
* possible.                                                                       *
* Usage: dp[limit]                                                                *
* Notation: w[i]:   weights array                                                 *
*           v[i]:   values array                                                  *
*           n:      number of items                                               *
*           limit:  "backpack size"                                               *
**********************************************************************************/

const int N = 1e5+5; // Maximum number of items
const int L = 1e5+5; // Maximum value for 'limit'

int ans, n, limit, w[N], v[N], dp[L];

int main () {
    cl(w, 0); cl(v, 0); cl(dp, 0);

    scanf("%d%d", &n, &limit);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &w[i], &v[i]);

    for (int i = 0; i < n; i++) // Adding item by item to our dp
        for (int j = w[i]; j < L; j++)
//      If there's an item limitation, create a DECREASING j loop! Like this:
//      for (int j = L-1; j >= w[i]; j--)
            dp[j] = max(dp[j], v[i]+dp[j-w[i]]);

    ans = dp[limit];
}
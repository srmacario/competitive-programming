/**********************************************************************************
* TRIE OF BITS (MAX XOR IN ARRAYS)                                                *
*                                                                                 *
* Problem: Given an array a[i] and an integer y, find max value of y^a[i].        *
* Idea: Create a trie of bits for all a[i], from the most to the least            *
* significant bit. Then try to traverse the path of inverted y, in a way that the *
* XOR will be maximized => query(y)                                               *
*                                                                                 *
* Another problem: Given an array a[i], find the subarray with maximum XOR.       *
* Idea: For each i, the trie will already have the results for a[1]^a[2]^...^a[j] *
* for all j up to i-1. Answer is query(sum), where sum is a[1]^...^a[i].          *
* In short: sum = sum^a[i]; ans = max(ans, query(sum)), add(sum)                  *
* [Do not forget to insert element 0 beforehand!]                                 *
*                                                                                 *
* One more problem: Consider a tree with weighted edges. For each node, find the  *
* maximum distance starting from it, where the distances are the XOR of weights.  *
*                                                                                 *
* Idea: Compute every dist(1, i), where 1 is the tree root. Then dist(i, j) =     *
* = dist(1, i)^dist(1, j) because all weights between 1 and lca(i, j) will be     *
* cancelled. Afterwards, solve the first problem where for each y = a[i] and      *
* a[i] = dist(1, i).                                                              *
**********************************************************************************/

struct Node {
    Node* ch[2];
    Node () {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

// Add new number to trie
void add (ll x) {
    Node* cur = root;
    for (ll j = 31; j >= 0; j--) {
        ll b = (((1ll << j)&x) > 0);
        if (!cur->ch[b]) cur->ch[b] = new Node();
        cur = cur->ch[b];
    }
}

// Returns max xor or the array
// number that provides max xor
ll query (ll x) {
    Node* cur = root;
    ll maxxor = 0;
    ll arrnum = 0;
    for (ll j = 31; j >= 0; j--) {
        ll b = (((1ll << j)&x) > 0);
        if (cur->ch[!b]) {
            cur = cur->ch[!b];
            maxxor += (1ll << j);
            if (!b) arrnum += (1ll << j);
        } else {
            cur = cur->ch[b];
            if (b) arrnum += (1ll << j);
        }
    }
    return maxxor;
    // return arrnum;
}

// Max XOR subarray
int main () {
    // int n, x;
    // scanf n

    ll xorsum = 0;
    ll ans = 0;

    root = new Node();

    add(0, root);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        xorsum = xorsum^x;
        ans = max(ans, query(xorsum));
        add(xorsum);
    }

    delete root;

    printf("%lld\n", ans);

    return 0;
}
/**********************************************************************************
* BIT/FENWICK TREE (QUICK RANGE SUM / POINT UPDATE)                               *
* Description: BIT/Fenwick Tree structure performs two operations: update and     *
* query, both with time complexity O(logN). A naïve approach would take O(1) to   *
* update and O(N) to query, whereas a prefix sum would take O(N) to update and    *
* O(1) to query.                                                                  *
* Its secret is to store subsums in a clever way. For instance, the parts of      *
* [0, 14] stored are [0, 7], [8, 11], [12, 13] and [14, 14].                      *
* query(pos) evaluates sum in range [0, pos]. In order to calculate sum in range  *
* [a, b], a > 0, make query(b)-query(a-1) or simply call rangesum(a, b).          *
* Time complexity: O((Q+U)logN)                                                   *
* Usage: add(pos, val), query(pos), rangesum(a, b)                                *
* Notation: p: position such as query(p) = sum [0, p]                             *
*           v: value to be added to pos p when update                             *
**********************************************************************************/

const int N = 1e5+10; // Vector size

int bit[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int rangesum (int a, int b) {
    return query(b)-(a ? query(a-1) : 0);
}
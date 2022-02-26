/**********************************************************************************
* KADANE'S ALGORITHM (MAX SUM OF A SEQUENCE)                                      *
* Description: Calculates the maximum consecutive sum in a given sequence. It     *
* basically iterates through the sequence storing two variables, max_now and      *
* maxsofar. For each number, it gets the best between expanding the interval      *
* or starting a new one, i.e. maxnow = max(maxnow+v[i], v[i]). Also, maxsofar is  *
* the maximum value maxnow has ever had. Example:                                 *
* The maximum sum in the sequence {-5, 3, 5, -1, 11, -7} is 18, represented by    *
* the subsequence {3, 5, -1, 11}.                                                 *
* Time complexity: O(N)                                                           *
* Notation: s[N]:      sequence                                                   *
*           n:         sequence length                                            *
*           maxnow:    max sum in current interval                                *
*           maxsofar:  final answer, max global sum                               *
**********************************************************************************/

const int N = 1e5+10; // Upper limit to n

int n;
ll s[N], maxnow, maxsofar;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &s[i]);

    maxnow = maxsofar = s[0];

    for (int i = 1; i < n; i++) {
        maxnow = max(maxnow+s[i], s[i]);
        maxsofar = max(maxsofar, maxnow);
    }

    // 2nd alternative: We can now have an empty subsequence,
    // i.e. maxsofar in sequence {-1, -1, -1} could be 0.

    /*
    maxnow = maxsofar = 0;
    for (int i = 0; i < n; i++) {
        maxnow = max(maxnow+s[i], 0);
        maxsofar = max(maxsofar, maxnow);
    }
    */

    printf("%lld\n", maxsofar);

    return 0;
}
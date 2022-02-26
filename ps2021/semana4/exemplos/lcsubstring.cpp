/**********************************************************************************
* LCSub (LONGEST COMMON SUBSTRING)                                                *
* Description: Calculates the LENGTH of the longest common substring (or          *
* contiguous subsequence) between two arrays or strings. Example:                 *
* LCSub("ABCD", "ACDF") = "CD", which has length 2. m[i][j] stands for longest    *
* common suffix, and max(m[i][j]) is our LCSub answer.                            *
* Time complexity: O(M*N)                                                         *
* Notation: m[i][j]: matrix of results                                            *
**********************************************************************************/

const int N = 1e3;  // Maximum string length
char s1[N], s2[N];
int m[N][N], len1, len2;

int lcsub () {
    int ans = 0;
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1])
                m[i][j] = 1 + m[i-1][j-1];
            ans = max(ans, m[i][j]);
        }
    return ans;
}
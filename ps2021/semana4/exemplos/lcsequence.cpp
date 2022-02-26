/**********************************************************************************
* LCS (LONGEST COMMON SUBSEQUENCE)                                                *
* Description: Calculates the LENGTH of the longest common subsequence between    *
* two arrays or strings. Example: LCS("ABCD", "ACDF") = "ACD", which has length   *
* 3.                                                                              *
* Time complexity: O(M*N)                                                         *
* Usage: m[len1][len2]                                                            *
* Notation: m[i][j]: matrix of results                                            *
**********************************************************************************/

const int N = 1e3;  // Maximum string length
char s1[N], s2[N];
int m[N][N], len1, len2;

int lcs () {
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            if (s1[i-1] == s2[j-1])
                m[i][j] = 1 + m[i-1][j-1];
            else
                m[i][j] = max(m[i][j-1], m[i-1][j]);
    return m[len1][len2];
}
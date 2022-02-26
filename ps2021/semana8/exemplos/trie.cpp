/**********************************************************************************
* TRIE (PREFIX TREE / STRING MATCHING)                                            *
*                                                                                 *
* Problem: Given a list of words and some queries, determine if each word is      *
* in the list or not.                                                             *
* Idea: When the prefix tree is built, you only need to traverse O(N) nodes for   *
* each word. In some cases you might want to add an '$' at the end of the word,   *
* when a word can be a prefix of another one.                                     *
**********************************************************************************/

struct Node {
    int cnt = 0;
    Node* ch[27];
    Node () : cnt(0) {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

void add (string s) {
    Node* cur = root;
    cur->cnt++;
    for (auto c : s) {
        if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
        cur = cur->ch[c-'a'];
        cur->cnt++;
    }
    if (!cur->ch[26]) cur->ch[26] = new Node();
    cur = cur->ch[26];
    cur->cnt++;
}

int match (string s) {
    Node* cur = root;
    for (auto c : s) {
        if (!cur->ch[c-'a']) return false;
        cur = cur->ch[c-'a'];
    }
    if (!cur->ch[26]) return false; // If you only need to count prefixes (not
                                    // the exact word), comment this line
    return cur->cnt;
}

int main () {
    root = new Node();
}
// LIGHTWEIGHT VERSION:
// For each node u, trie[u][c] = v if there is an edge from u using letter c, and
//                  trie[u][c] = 0 otherwise.
// u, v are integers related to the number of nodes in the trie.
// The trie starts with 1 node (the root), labeled with 1, and its edges are
// trie[1][i] for i = 0..26.

int trie[N][26], trien = 1;

int add (int u, char c){
    c -= 'a';
    if (trie[u][c]) return trie[u][c];
    return trie[u][c] = ++trien;
}

// Add a string s in the trie
// u is initially 1 and its pointer is moved to one of its children: u = add(u, c)
int u = 1;
for (char c : s) u = add(u, c);
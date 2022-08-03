#include "testlib.h"
using namespace std;
 
const int MAXN = 5e4 - 5;
const int MAXM = 1e5;
const int MAXT = 1e8;
 
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	for(int test = atoi(argv[1]); test <= atoi(argv[2]); test++){
		startTest(test);
		int n = MAXN;
		int m = 2 * n;
		cout << n << " " << m << " " << rnd.next(1, MAXT) << '\n';
		for(int i = 1; i < n; i++){
			cout << i + 1 << " " << i + 2 << " " << rnd.next(1, MAXM) << '\n';
        }
	}
 
	return 0;
}
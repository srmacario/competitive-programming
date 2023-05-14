#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
char s[10], s1[10], s2[10];

int main(){
	scanf("%d", &n);
	if(n == 3){
		printf("WEIGHT 1 1 2\n");
		fflush(stdout);
		scanf(" %s", s1);
		printf("WEIGHT 1 1 3\n");
		fflush(stdout);
		scanf(" %s", s2);
		if(s1[0] == 'E'){
			if(s2[0] == 'L')
				printf("ANSWER -3\n");
			else
				printf("ANSWER 3\n");
		}
		else if(s1[0] == 'L'){
			if(s2[0] == 'E')
				printf("ANSWER -2\n");
			else
				printf("ANSWER 1\n");
		}
		else{
			if(s2[0] == 'E')
				printf("ANSWER 2\n");
			else
				printf("ANSWER -1\n");
		}
		fflush(stdout);
	}
	else{
		for(int i = 1; i <= n; i++)
			v.push_back(i);
		printf("WEIGHT %d", v.size() / 4);
		for(int i = 0; i < v.size() / 4; i++)
			printf(" %d", v[i]);
		for(int i = 0; i < v.size() / 4; i++)
			printf(" %d", v[i + v.size() / 4]);
		printf("\n");
		fflush(stdout);
		scanf(" %s", s);
		if(s[0] == 'E')
			for(int i = 0; i < 2 * v.size() / 4; i++){
				swap(v[i], v[n - 1]);
				n--;
			}
		else
			n = 2 * v.size() / 4;
		while(n > 1){
			printf("WEIGHT %d", n / 2);
			for(int i = 0; i < n / 2; i++)
				printf(" %d", v[i]);
			for(int i = 0; i < n / 2; i++)
				printf(" %d", v[v.size() - 1 - i]);
			printf("\n");
			fflush(stdout);
			scanf(" %s", s);
			if(s[0] == 'E'){
				int h = n / 2;
				for(int i = 0; i < h; i++){
					swap(v[i], v[n - 1]);
					n--;
				}
			}
			else
				n /= 2;
		}
		if(s[0] == 'L')
			printf("ANSWER %d\n", v[0]);
		else
			printf("ANSWER -%d\n", v[0]);
		fflush(stdout);
	}
	return 0;
}
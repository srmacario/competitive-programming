#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=2e5+5;

int t;
string pat, txt, aux;
char s[1010];

bool fun(){
	int p=0;
	for(int i=0;i<pat.size();i++){
		if(p==txt.size()) return false;
		if(txt[p]=='*'){
			if(pat[i]==txt[p-1]) continue;
			else p++;
		}
		if(p==txt.size()) return false;
		if(txt[p]==pat[i]) p++;
		else{
			p++;
			if(p==txt.size() || txt[p]!='*') return false;
			i--;
		}
	}
	if(p<txt.size()){
		if(txt[p]!='*') p++;
		if(p==txt.size()) return false;
		while(p<txt.size()){
			if(txt[p]!='*') return false;
			p+=2;
		}
		return p==txt.size()+1;
	}
	return true;
}

int main(){
	scanf(" %s", s);
	t=strlen(s);
	for(int i=0;i<t;i++){
		if(s[i]=='+'){
			aux+=s[i-1];
			aux+='*';
		}
		else aux+=s[i];
	}
	for(int i=0;i<aux.size();i++){
		if(aux[i]=='*' && i+1<aux.size() && aux[i+1]==aux[i-1]){
			if(i+2<aux.size() && aux[i+2]=='*') i++;
			else{
				txt+=aux[i-1];
				aux[i]=aux[i-1];
				aux[i+1]='*';
			}
		}
		else txt+=aux[i];
	}
	scanf(" %s", s);
	pat=s;
	if(fun()) printf("Yes\n");
	else printf("No\n");
	return 0;
}
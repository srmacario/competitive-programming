#include<bits/stdc++.h>
using namespace std;

string s;
vector<string> ans; 

int main(){
	cin>>s;
	for(int i=0;i<10;i++){
		string c;
		for(int i=0;i<s.size();i++){
			if(s[i]>'0') c+='1';
			else if(!c.empty()) c+='0';
			s[i]--;
		}
		if(c.empty()) break;
		ans.push_back(c);
	}
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size()-1;i++) cout<<ans[i]<<" ";
	cout<<ans.back()<<"\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pb push_back

int main(){
    int n ;
    scanf("%d",&n);
    while(n){
        stack<int> st2;
        queue <int> st1, stfinal;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            st1.push(x);
        }
        int num = 1;
        while(st1.size()){
            if(st1.front() == num) stfinal.push(num++);
            else st2.push(st1.front());
            st1.pop();
        }
        while(st2.size()){
            stfinal.push(st2.top());
            st2.pop();
        }
        int k = 1;
        bool ok = true;
        while(stfinal.size()){
            if(stfinal.front() != k) ok = false;
            stfinal.pop();
            k++;
        }
        printf("%s\n", ok ? "yes" : "no");
        scanf("%d",&n);
    }
    return 0;
}
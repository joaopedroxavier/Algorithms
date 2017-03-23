//
//	P13 - Parentheses Balance
//	Judge: UVa
//	source: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=614
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;


int main(){
	int n;
	bool ans = true;
	string a;
	stack<char> st;
	cin >> n;
	getline(cin,a);
	for(int i=0;i<n;++i){
		ans = true;
		while(!st.empty()) st.pop();
		getline(cin,a);
		if(a.size()==0){
			cout << "Yes" << endl;
			continue;
		}
		for(unsigned i=0;i<a.size();++i){
			if(a[i]=='(' or a[i] == '[')	st.push(a[i]);
			else{
				if(st.empty()){
					cout << "No" << endl;
					ans = false;
					break; 
				}
				else{
					if(st.top()=='(' and a[i] == ')') st.pop();
					else if(st.top()=='[' and a[i] == ']') st.pop();
					else{
						cout << "No" << endl;
						ans = false;
						break;
					}
				}
			}
		}
		if(ans){
			if(st.empty())	cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}


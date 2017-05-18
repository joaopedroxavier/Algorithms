//
//	(Transform the Expression)
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/ONP/
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << ",  " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string rpn(string a){
	stack<char> st;
	int cont=0;
	if (a.size() == 1){
		return a;
	}
	for(char u : a){
		cont++;
		if(cont==2 and u!='(') break;
		else if(u == '(')
			st.push(u);
		else if(u == ')'){
			st.pop();
			if(st.size() == 1) break;
		}
	}
	string a1 = a.substr(1,cont-1);
	string a2 = a.substr(cont,1);
	string a3 = a.substr(cont+1, a.size()-cont-2);
	return rpn(a1)+rpn(a3)+a2;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	string s;
	for(int i=0;i<t;++i){
		cin >> s;
		cout << rpn(s) << endl;
	}
	return 0;
}


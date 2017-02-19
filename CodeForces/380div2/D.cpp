//
//	(D - Sea Battle)
//	Codeforces Round #380 Div.2 (Based on Technocup 2017 - Elimination Round 2)
//	source: http://codeforces.com/contest/738/problem/D
//
#include <bits/stdc++.h>

using namespace std;

#define make_pair mp
#define push_back pb

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;

int main(){
	int n, a, b, k, cont=0, ans=0; 
	string s, shoot;
	cin >> n >> a >> b >> k >> s;
	shoot = s;
	for(int i=0;i<n;++i){
		if(s[i] == '0'){
			cont++;
			if(cont%b==0){
				shoot[i] = 'y';
				ans++;
			}
		}
		else cont=0;
	}
	ans = ans - (a-1);
	cout << ans << endl;
	cont=0;
	for(int i=0;i<n;++i){
			if(shoot[i]=='y'){
				cout << i+1 << ' ';
				cont++;
			}
			if(cont>=ans) break;
	}
	cout << endl;
	return 0;
}


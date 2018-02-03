//
//	(A - Vladik and flights)
//	CodeForces Round #384 Div.2
//	source: http://codeforces.com/contest/743/problem/A
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
	int n, a, b;
	string s;
	cin >> n >> a >> b;
	cin >> s;
	if(s[a-1]!=s[b-1]) cout << "1" << endl;
	else cout << "0" << endl;
	return 0;
}

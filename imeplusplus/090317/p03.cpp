//
//	P3 - Equivalent Strings
//	Judge: CodeForces
//	source: http://codeforces.com/problemset/problem/559/B
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

bool is_equivalent(string a, string b, int n){
	if(n%2==1) return (a==b);
	string a1 = a.substr(0,n/2);
	string b1 = b.substr(0,n/2);
	string a2 = a.substr(n/2);
	string b2 = b.substr(n/2);
	return ((is_equivalent(a1,b2,n/2) and is_equivalent(a2,b1,n/2)) or (is_equivalent(a1,b1,n/2) and is_equivalent(a2,b2,n/2)));
}

int main(){
	string a, b;
	unsigned n;
	cin >> a >> b;
	n = a.size();
	if(is_equivalent(a,b,n)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}


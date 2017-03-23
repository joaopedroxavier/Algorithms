//
//	(B - Chloe and the sequence)
//	CodeForces Round #384 Div.2
//	source: http://codeforces.com/contest/743/problem/B
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e5;
const int INF=0x3f3f3f3f;

int main(){
	ll n, k, i=1, cont=0;
	cin >> n >> k;
	while(1){
		cont++;
		if((k-i)%(2*i)==0) break;
		i*=2;
	}
	cout << cont << endl;
}


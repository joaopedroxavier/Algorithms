//
//	(B - Decoding)
//	CodeForces Round #386 Div.2
//	source: http://codeforces.com/contest/746/problem/B
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
	ios::sync_with_stdio(false);
	int n, cont=0;
	string s;
	cin >> n;
	cin >> s;
	deque<char> d;
	if(s.size()%2==0) cont++;
	for(char a : s){
		(cont%2) ? d.push_front(a) : d.push_back(a);
		cont++;
	}
	while(!d.empty()){
		cout << d.front();
		d.pop_front();
	}
	cout << endl;
	return 0;
}


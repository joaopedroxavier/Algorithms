//
//	(A - Arpa's hard exam and Mehrdad's naive cheat)
//	CodeForces Round #383 Div.2
//	source: http://codeforces.com/contest/742/problem/A
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
	int a[4] = {6,8,4,2};
	cin >> n;
	if(!n) cout << "1" << endl;
	else cout << a[(n%4)] << endl;
	return 0;
}


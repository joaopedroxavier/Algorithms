//
//	(C - Tram)
//	CodeForces Round #386 Div.2
//	source: http://codeforces.com/contest/746/problem/C
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
	ios_base::sync_with_stdio(false);
	double s, x1, x2, t1, t2, p, d;
	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
	if(d == 1){
		if(x2>x1){
			if(p<=x1) cout << min(abs(x2-x1)*t2, abs(x2-p)*t1) << endl;
			else cout << min(abs(x2-x1)*t2, (abs(s-p)+s+x2)*t1) << endl;
		}
		else	cout << min(abs(x2-x1)*t2, (abs(s-x2)+abs(s-p))*t1) << endl;
	}
	else{
		if(x2>x1)	cout << min(abs(x2-x1)*t2, (abs(p)+abs(x2))*t1) << endl;
		else{
			if(p>=x1) cout << min(abs(x2-x1)*t2, abs(x2-p)*t1) << endl;
			else cout << min(abs(x2-x1)*t2, (p+s+abs(x2-s))*t1) << endl;
		}
	}
	return 0;
}


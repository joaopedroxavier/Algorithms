//
//
//
//
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

ll a[3], b[3];
int main(){
	ios_base::sync_with_stdio(false);
	bool ans = true;
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
	sort(a,a+3);
	sort(b,b+3);
	if(a[2]*a[2] != (a[1]*a[1] + a[0]*a[0])) ans = false;	
	else if(b[2]*b[2] != (b[1]*b[1] + b[0]*b[0])) ans = false;
	else for(int i=0;i<3;++i) if(a[i]!=b[i]) ans = false;
	cout << ((ans) ? "YES" : "NO") << endl;
	return 0;
}


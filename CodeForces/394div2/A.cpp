//
// A - Dasha and Stairs
// CodeForces Round #394 Div.2
// Source: http://codeforces.com/contest/761
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int main(){
	ios_base::sync_with_stdio(false);
	int e, o;
	cin >> e >> o;
	cout << ((abs(e-o) > 1 or (o==0 and e==0)) ? "NO" : "YES") << endl;
	return 0;
}


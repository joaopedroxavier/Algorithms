//
// A - Petr and a Calendar
// CodeForces Round #393 Div.2
// Source: http://codeforces.com/contest/760
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

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	ios_base::sync_with_stdio(false);
	int m, d, ans=1;
	cin >> m >> d;

	for(int i=1;i<days[m-1];++i){
		d = (d+1)%7;
		if(d == 1) ans++;
	}

	cout << ans << endl;

	return 0;
}


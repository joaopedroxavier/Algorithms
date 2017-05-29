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

vi dv;

int main(){
	ios_base::sync_with_stdio(false);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	for(int i=1;i*i<=c;++i) if(!(c%i)){
		dv.pb(i), dv.pb(c/i);
	}
	sort(dv.begin(), dv.end());
	for(int j : dv) if(!(j%a) and (j%b) and (d%j)){
		cout << j << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}


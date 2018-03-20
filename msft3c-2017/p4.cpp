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
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int main(){
	ios_base::sync_with_stdio(false);
	int st, tg, v, t;
	char c;
	while(1){
		ll ans = 0;
		cin >> st >> c >> tg >> c >> v >> c >> t;
		if(cin.eof())	break;
		if(st <= (tg-v)){
			cout << "not possible" << endl;
			continue;
		}
		t-=(st-(tg-v+1));
		st=(tg-v+1);
		while(t>4*v){
			t-=4*v;
			ans += 5;
			ans += 10*2*v;
		}
		if(t>1){
			ans += 5;
			t--;
			ans += 10*((t+1)/2);
		}
		cout << ans << endl;
	}
	return 0;
}


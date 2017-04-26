//
//	(D - Winter is Coming)
//	CodeForces Round #387 Div.2
//	source: http://codeforces.com/contest/747/problem/D
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << ",  " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int temp[N];
vi winter;
vector<int> len;
int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> temp[i];
		if(temp[i] < 0){
				winter.pb(i);
				if(winter.size()>=2)	len.pb(-(winter[winter.size()-1]-winter[winter.size()-2]-1));
		}
	}
	sort(len.begin(), len.end());
	int ans = winter.size()*2;
	if((int)winter.size() > k) cout << -1 << endl;
	else{
		k-=winter.size();
		while(!len.empty() and k>=0){
			if((-(len.back())>k)) break;
			k-=(-(len.back()));
			len.pop_back();
			ans-=2;
		}
		if(winter.empty()){
			cout << 0 << endl;
			return 0;
		}
		if(k > (n-winter[winter.size()-1]-1)) ans--;
		cout << ans << endl;
	}	
	return 0;
}


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

int a[N]; 
vector<ii> ans;

int main(){
	ios::sync_with_stdio(false);
	int n;
	bool has_ans = false;
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	int last=0;
	for(int i=0;i<n;++i){
		if(a[i] != 0){
			last = i;
			has_ans = true;
		}
	}
	for(int i=0;i<n;++i){
		int cont=i;
		while(a[cont] == 0 and cont < n) cont++;
		if(cont == last){
			ans.pb(mp(i,n-1));
			break;
		}
		else ans.pb(mp(i,cont));
		i=cont;
	}
	if(!has_ans) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(int i=0;i<(int)ans.size();++i) cout << ans[i].first+1 _ ans[i].second+1 << endl;
	}
	return 0;
}


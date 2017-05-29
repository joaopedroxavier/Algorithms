//
//
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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll w[N], ans;
multiset<ll> l, r;

ll getmed(){
	if(r.size() > l.size()) return *(r.begin());
	return *(prev(l.end()));
}

void add(int x){
	if(x < *r.begin()) l.insert(x);
	else r.insert(x);

	if(r.size() > l.size()) l.insert(*(r.begin())), r.erase(r.begin());
	else if(l.size() > r.size()) r.insert(*prev(l.end())), l.erase(prev(l.end()));
}

void rem(int x){
	if(l.count(x)) l.erase(l.find(x));
	else r.erase(r.find(x));

	if(r.size() > l.size()) l.insert(*(r.begin())), r.erase(r.begin());
	else if(l.size() > r.size()) r.insert(*prev(l.end())), l.erase(prev(l.end()));
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;++i) cin >> w[i];

	for(int i=0;i<k;++i) add(w[i]);

	for(int i=k;i<n;++i){
		add(w[i]);
		rem(w[i-k]);
		ans = max(ans, getmed());
	}

	cout << ans << endl;

	return 0;
}


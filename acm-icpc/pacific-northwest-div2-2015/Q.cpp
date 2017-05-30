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

int rat[N];
int main(){
	ios_base::sync_with_stdio(false);
	int n, ans=INF;
	cin >> n;
	for(int i=0; i<n; ++i) cin >> rat[i];
	sort(rat, rat+n);
	int p1 = 0, p2 = n-1;
	while(p1<p2){
		ans = min(ans, rat[p1]+rat[p2]);
		p1++;
		p2--;
	}
	cout << ans << endl;
	return 0;
}


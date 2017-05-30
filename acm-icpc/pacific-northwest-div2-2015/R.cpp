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

vector<pair<string, string> > v;
int n;
char s[20], t[20];

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
					scanf("%s%s", s, t);
					v.pb(mp(t, s));
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++) {
					printf("%s %s\n", v[i].second.c_str(), v[i].first.c_str());
	}
	return 0;
}


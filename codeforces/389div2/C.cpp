//
// C - Santa Claus and Robot
// CodeForces Round #389 Div.2
// Source: http://codeforces.com/contest/752
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

string s;
int n, ans=1;

bool lrORud(set<char> s){
	return ((s.count('L') and s.count('R')) or (s.count('U') and s.count('D')));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	set<char> st;
	for(int i=0;i<n;++i){
		st.insert(s[i]);
		if(st.size() > 2 or lrORud(st)) ans++, i--, st.clear();
	}
	cout << ans << endl;
	return 0;
}


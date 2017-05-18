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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int ans[] = {4, 0, 0, 0};

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	int n = s.size(), p1 = ((n == 1) ? 0 : s[n-2]-'0'), p2 = s[n-1] - '0';
	cout << ans[(p1*10 + p2) % 4] << endl;
	return 0;
}


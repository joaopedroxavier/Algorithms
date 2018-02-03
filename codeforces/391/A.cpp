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

map<char, int> m;

int main(){
	ios_base::sync_with_stdio(false);

	string s, bulb = "Bulbasaur";
	int ans = INF;
	cin >> s;

	for(char c : s) m[c]++;
	for(char c : bulb) ans = min(ans, ((c == 'a' or c == 'u') ? m[c]/2 : m[c]));

	cout << ans << endl;
	return 0;
}


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

set<char> vowel;

int main(){
	ios_base::sync_with_stdio(false);
	string s, r, front, back;
	vowel.insert('a'), vowel.insert('e'), vowel.insert('i'), vowel.insert('o'),	vowel.insert('u');
	cin >> s;
	r = s;
	reverse(r.begin(), r.end());
	for(char c : s) if(vowel.count(c)) front.pb(c);
	for(char c : r) if(vowel.count(c)) back.pb(c);
	cout << ((front == back) ? "S" : "N") << endl;
	return 0;
}


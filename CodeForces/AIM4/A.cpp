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
int k;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> s >> k;
  set<char> m;
  for(char c : s) m.insert(c);
  if(k > (int)s.size()) return cout << "impossible" << endl, 0;
  if(k < (int)m.size()) return cout << 0 << endl, 0;
  else cout << k - (int)m.size() << endl;
	return 0;
}


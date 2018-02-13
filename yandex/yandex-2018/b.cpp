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
set<pair<int, string>> ss;

bool pal(int i, int j) {
  int p1 = i, p2 = j;
  while(p1 <= p2) {
    if(s[p1] != s[p2]) return false;
    p1++, p2--;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  int n = (int) s.size();

  for(int i=0; i<n-1; i++) if(pal(i, i+1)) {
    ss.insert(mp(2, s.substr(i, 2)));
  }

  for(int i=0; i<n-2; i++) if(pal(i, i+2)) {
    ss.insert(mp(3, s.substr(i, 3)));
  }

  if(!ss.empty()) cout << (*ss.begin()).second << endl;
  else cout << -1 << endl;

	return 0;
}


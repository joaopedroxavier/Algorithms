#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

vector<ii> derange;
string s;

void process() {
  for(int i=0; i<(int)s.size(); i++) {
    int pos = i;
    for(int j=pos; j<(int)s.size(); j++) {
      if(s[j] < s[pos]) pos = j;
    }
    if(i != pos) {
      swap(s[i], s[pos]);
      derange.push_back({pos, i});
    }
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  process();

  reverse(derange.begin(), derange.end());
  for(ii p : derange) {
    cout << p.first+1 << " " << p.second+1 << endl;
  }
	return 0;
}


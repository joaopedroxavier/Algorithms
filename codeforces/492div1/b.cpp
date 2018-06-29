//
// Elohim Essaim, Elohim Essaim, I implore you...
//
#include <bits/stdc++.h>

using namespace std;

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

vector<int> current;
ll cost;
int n;

void step(vector<int>& v) {
  if(v.empty()) return;

  while(!v.empty() and v[0] == v[1]){ v.erase(v.begin()); v.erase(v.begin()); }

  if(v.empty()) return;

  auto it = v.begin() + 1;
  while(*it != v.front()) it++, cost++;

  v.erase(it);
  v.erase(v.begin());
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<2*n; i++) {
    int u; scanf("%d", &u);
    current.push_back(u);
  }

  while(!current.empty()) step(current);

  printf("%lld\n", cost);
	return 0;
}


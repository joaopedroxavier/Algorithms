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

const int N = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int adj[10][10][N];
int firstocc[10];
string s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int n = (int)s.size();

  memset(adj, 63, sizeof adj);
  memset(firstocc, 63, sizeof firstocc);

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      int a = s[i] - '0';
      int b = s[j] - '0';

      firstocc[a] = min(firstocc[a], i);
      adj[a][b][i] = min(adj[a][b][i], j);
    }
  }

  vector<int> v;
  for(int i=0; i<10; i++) v.push_back(i);

  int ans = 0;

  do {
    int p = firstocc[v[0]]; int i = 0;
    while(p < n and i < 10) {
      p = adj[v[i]][v[i+1]][p];
      i++;
    }
    if(i == 10) ans++;
  } while(next_permutation(v.begin(), v.end()));

  printf("%d\n", ans);
	return 0;
}


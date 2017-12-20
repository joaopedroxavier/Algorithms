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

int n, m, v[N];

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    for(int j=x+1; j<=y; j++) {
      v[j] = 1;
    }
  }

  bool ans = true;
  for(int i=1; i<=m; i++) ans = ans and v[i] > 0;

  printf("%s\n", ans ? "YES" : "NO");

	return 0;
}


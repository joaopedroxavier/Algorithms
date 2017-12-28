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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, cost[N];

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<=n; j++) {
      for(int k=i; k<j; k++) {
        cost[k]++;
      }
    }
  }

  int ans = 0;
  for(int i=0; i<n; i++) ans = max(ans, cost[i]);

  printf("%d\n", ans);

	return 0;
}


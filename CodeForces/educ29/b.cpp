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

int n, w[N];
int ans = INF;

int main(){
  scanf("%d", &n);
  n *= 2;
  for(int i=1; i<=n; i++) scanf("%d", &w[i]);

  sort(w, w+n+1);

  for(int i=1; i<=n; i++) {
    for(int j=i+1; j<=n; j++) {
      int p = 0, sum = 0;
      for(int k=1; k<=n; k++) {
        if(k == i or k == j) continue;

        if(p){sum += abs(w[k] - p); p = 0;}
        else p = w[k];
      }
      ans = min(ans, sum);
    }
  }

  printf("%d\n", ans);

	return 0;
}


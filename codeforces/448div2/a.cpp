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

int n, a[N], best[N];

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++) {
    int p=i, sum=0;
    while(sum < 180){ sum+=a[p], p = (p+1)%n; }
    best[i] = abs(sum - (360 - sum));
  }

  int ans = INF;
  for(int i=0; i<n; i++) ans = min(ans, best[i]);

  printf("%d\n", ans);

	return 0;
}


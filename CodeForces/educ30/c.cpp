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

int a[N][N];
int n, m, k;
int ans1, ans2;

int main(){
  scanf("%d %d %d", &n, &m, &k);
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &a[i][j]);

  for(int j=0; j<m; j++) {
    int ma = 0, num = 0, rem = 0;
    for(int i=0; i<n; i++) if(a[i][j]) {
      num++;
      int cont = 0, sum = 0;
      for(int p=i; p<n and cont<k; p++) {
        sum += a[p][j];
        cont++;
      }
      if(sum > ma) ma = sum, rem = num - 1;
    }
    ans1 += ma, ans2 += rem;
  }

  printf("%d %d\n", ans1, ans2);

	return 0;
}


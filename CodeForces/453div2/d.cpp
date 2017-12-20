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

int n, p[200][200];

int main(){
  scanf("%d", &n);
  p[0][0] = 1;
  p[1][0] = 0; p[1][1] = 1;

  for(int i=2; i<=n; i++) {
    p[i][0] = p[i-2][0];
    for(int j=1; j<200; j++) {
      p[i][j] = (p[i-1][j-1] + p[i-2][j]) % 2;
    }
  }

  int d1 = 0;
  for(int i=0; i<200; i++) d1 = max(d1, p[n][i] ? i : 0);
  int d2 = 0;
  for(int i=0; i<200; i++) d2 = max(d2, p[n-1][i] ? i : 0);

  printf("%d\n", d1);
  for(int i=0; i<=d1; i++) printf("%d ", p[n][i]);
  printf("\n");
  printf("%d\n", d2);
  for(int i=0; i<=d2; i++) printf("%d ", p[n-1][i]);
  printf("\n");

  return 0;
}


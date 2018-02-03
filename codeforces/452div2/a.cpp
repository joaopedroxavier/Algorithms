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

int n, ans;
int n2, n1;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    int g;
    scanf("%d", &g);
    if(g == 1) n1++;
    else n2++;
  }

  int m = min(n1, n2);
  ans += m;
  n1 -= m;
  n2 -= m;

  ans += (n1/3);

  printf("%d\n", ans);

	return 0;
}


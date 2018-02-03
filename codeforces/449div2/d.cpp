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

int n, m, c, v[N];

void query(int i) {
  int u;
  scanf("%d", &u);
  if(u <= c/2) {
    for(int i=1; i<=n; i++) {
      if(!v[i] or (v[i] and v[i] > u)) {
        v[i] = u;
        printf("%d\n", i);
        fflush(stdout);
        break;
      }
    }
  } else {
    for(int i=n; i>0; i--) {
      if(!v[i] or (v[i] and v[i] < u)) {
        v[i] = u;
        printf("%d\n", i);
        fflush(stdout);
        break;
      }
    }
  }

  bool check = true;
  for(int i=1; i<=n; i++) check = check and v[i];

  if(i > m or check) {
    return;
  }
  else query(i+1);
}

int main(){
  scanf("%d %d %d", &n, &m, &c);

  query(1);

  return 0;
}


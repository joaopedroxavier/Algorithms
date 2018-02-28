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

int n, t;

int main(){
  scanf("%d", &t);

  for(int i=0; i<t; i++) {
    scanf("%d", &n);
    vector<int> v(9);
    for(int i=8; i>=0; i--) {
      v[i] = n%10;
      n/=10;
    }

    vector<int> ans[8];
    for(int i=0; i<9; i++) {
      ans[0].pb(v[i] < 5);
      ans[1].pb(v[i] >=5);
      ans[2].pb(-1);
      ans[3].pb(!(v[i] % 5 == 0));
      ans[4].pb(!(v[i] % 5 == 1));
      ans[5].pb(!(v[i] % 5 == 2));
      ans[6].pb(!(v[i] % 5 == 3));
      ans[7].pb(!(v[i] % 5 == 4));
    }

    for(int i=0; i<8; i++) {
      for(int j=0; j<9; j++) {
        printf("%c", ans[i][j] == -1 ? '-' : '0' + ans[i][j]);
      }
      printf("\n");
    }

    printf("\n");
  }

	return 0;
}


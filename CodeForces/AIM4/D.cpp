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

int n, st, x;
int val, nex;

int main(){
  scanf("%d %d %d", &n, &st, &x);

  vector<int> v(n+1);
  for(int i=0;i<=n;i++) v[i] = i;
  random_shuffle(v.begin(), v.end());

  int bestn, bestval;

  printf("? %d\n", st);
  fflush(stdout);

  scanf("%d %d", &val, &nex);
  if(val >= x) return printf("! %d\n", val), 0;
  if(nex == -1) return printf("! -1\n"), 0;
  bestn = nex, bestval = val;

  if(n > 900){
    for(int i=0;i<=900;i++) if(v[i]){
      printf("? %d\n", v[i]);
      fflush(stdout);

      scanf("%d %d", &val, &nex);

      if(val > bestval and val < x){
        bestval = val, bestn = nex;
      }
    }
  }

  for(int i=0;i<=900;i++){
    printf("? %d\n", bestn);
    fflush(stdout);

    scanf("%d %d", &val, &nex);
    if(val >= x) return printf("! %d\n", val), 0;
    if(nex == -1) return printf("! -1\n"), 0; 
    bestn = nex;
  }

  printf("! -1\n");

  return 0;
}


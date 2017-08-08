#include <bits/stdc++.h>

using namespace std;


#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int v[N][2];
int n;

int solv(int x) {
  for (int i = 0; i < 2; i++) {
    int l = 0;
    for (int j = 0; j < n; j++) if (v[j][i] > x) {
      if (l and v[j][i] == l) l = 0;
      else if (l) return 0;
      else l = v[j][i];
    }
    if (l) return 0;
  }
  return 1;
}

int main(){
  while (~scanf("%d", &n)) {
    for(int i=0;i<n;i++) scanf("%d", &v[i][0]);
    for(int i=0;i<n;i++) scanf("%d", &v[i][1]);
    int l=0, r=1e9;
    while(l < r){
      int m = (l+r)/2;
      if(solv(m)) r = m;
      else l = m+1;
    }
    //cout << r << endl;
    printf("%d\n", l);
  }
  return 0;
}

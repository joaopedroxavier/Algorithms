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

int v[6], t;

int main(){
  for(int i=0; i<6; i++) scanf("%d", &v[i]), t += v[i];

  for(int i=0; i < (1<<6); i++) {
    int cnt = 0, sum = 0;
    for(int j=0; (1<<j) <= i; j++) if((1<<j) & i) {
      sum += v[j];
      cnt++;
    }
    if(cnt == 3) {
      if(sum == t - sum) return printf("YES\n"), 0;
    }
  }

  printf("NO\n");
	return 0;
}


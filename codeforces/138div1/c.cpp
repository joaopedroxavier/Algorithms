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
const int N=2e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll m1[N], m2[N], aux[N];
ll v[N], ans[N];
int n, k;

void sqr() {
  memset(aux, 0, sizeof aux);
  for(int i=0; i<n; i++) {
    for(int k=0; k<=i; k++) {
      aux[i] = (aux[i] + (m2[k]*m2[i-k]) % MOD) % MOD;
    }
  }

  for(int i=0; i<n; i++) {
    m2[i] = aux[i];
  }
  
}

void mul() {
  memset(aux, 0, sizeof aux);
  for(int i=0; i<n; i++) {
    for(int k=0; k<=i; k++) {
      aux[i] = (aux[i] + (m1[k]*m2[i-k]) % MOD) % MOD;
    }
  }

  for(int i=0; i<n; i++) {
    m1[i] = aux[i];
  }
}

void fexp(ll e) {
  while(e) {
    if(e&1) mul();
    sqr();
    e /= 2;
  }
}

void give_ans() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<=i; j++) {
      ans[i] = (ans[i] + (m1[j] * v[i-j]) % MOD) % MOD;
    }
  }
}

int main(){
  scanf("%d %d", &n, &k);

  for(int i=0; i<n; i++) {
    scanf("%lld", &v[i]);
  }

  m1[0] = 1;
  for(int i=0; i<n; i++) m2[i] = 1;

  fexp(k);
  give_ans();
  for(int i=0; i<n; i++) printf("%lld ", ans[i]);
  printf("\n");
	return 0;
}


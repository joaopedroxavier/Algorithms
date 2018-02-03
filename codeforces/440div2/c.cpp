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

int cnt = 0;
int n;

void check(int n) {
  if(n&1) {
    if(n < 9){ cnt -= 1; return; }
    else{ n -= 9; cnt++; check(n); }
  }
  else if(n % 4 == 2) {
    if(n < 6){ cnt = -1; return; }
    else{ n -= 6; cnt++; check(n); }
  }
  else {
    cnt += n/4;
    return;
  }
}

int main(){
  scanf("%d", &n);
  for(int u, i=0; i<n; i++) {
    scanf("%d", &u);
    cnt = 0;
    check(u);
    printf("%d\n", cnt);
  }

	return 0;
}


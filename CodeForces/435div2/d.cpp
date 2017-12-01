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

int n, d, nd, ask;
int pos[2];
string s;

void query(int l, int r, int ll, int rr) {
  if(pos[0] and pos[1]) return;
  if(ask >= 15) return;

  int p = s[l] - '0';
  for(int i=l; i<=r; i++) s[i] = '0' + p ^ 1;
  ask++;
  printf("? %s\n", s.c_str());
  fflush(stdout);
  scanf("%d", &nd);
  if(nd == d + (r-l+1)){ 
    pos[p] = l+1;
    d = nd;
    if(l == ll) {
      int mm = (r + 1 + rr)/2;
      query(r+1, mm, r+1, rr);
      query(mm+1, rr, r+1, rr);
    } else {
      int mm = (ll + l - 1)/2;
      query(ll, mm, ll, l-1);
      query(mm+1, l-1, ll, l-1);
    }
  }
  else if(nd == d - (r-l+1)){ pos[p^1] = l+1; d = nd; return; }
  else{
    if(l == r) return;
    d = nd;
    int m = (l+r)/2;
    query(l, m, l, r);
    query(m+1, r, l, r);
  }

  if(pos[0] and pos[1]) return;
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) s = s + '1';
  ask++;
  printf("? %s\n", s.c_str());
  fflush(stdout);
  scanf("%d", &d);

  query(0, (n-1)/2, 0, n-1);
  query((n-1)/2+1, n-1, 0, n-1);

  if(pos[0] and pos[1]) {
    printf("! %d %d\n", pos[0], pos[1]);
    fflush(stdout);
  } else {
    printf("0\n");
  }

  return 0;
}


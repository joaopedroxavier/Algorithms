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

bool isline[N], iscol[N];
int n, posl[N], posc[N], ans[N];
vector<ii> pos[N];
vector<int> seq[N];

int different(int x1, int x2, int t) {
  if(x1 != t) return x1;
  else return x2;
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<2*n; i++) {
    for(int j=0; j<n; j++) {
      int u;
      scanf("%d", &u);
      pos[u].pb(mp(i, j));
      seq[i].pb(u);
    }
  }

  for(int i=1; i <= n*n; i++) {
    pair<int, int> l1 = pos[i][0], l2 = pos[i][1];
    if(isline[l1.first]) {
      for(auto j : seq[l1.first]) {
        int d = different(pos[j][0].first, pos[j][1].first, l1.first);
        iscol[d] = true;
      }
      int p = l2.second * n + l1.second;
      ans[p] = i;
    }
    else if(isline[l2.first]) {
      for(auto j : seq[l2.first]) {
        int d = different(pos[j][0].first, pos[j][1].first, l2.first);
        iscol[d] = true;
      }
      int p = l1.second * n + l2.second;
      ans[p] = i;
    }
    else if(iscol[l1.first]) {
      for(auto j : seq[l1.first]) {
        int d = different(pos[j][0].first, pos[j][1].first, l1.first);
        isline[d] = true;
      }
      int p = l1.second * n + l2.second;
      ans[p] = i;
    }
    else if(iscol[l2.first]) {
      for(auto j : seq[l2.first]) {
        int d = different(pos[j][0].first, pos[j][1].first, l2.first);
        isline[d] = true;
      }
      int p = l2.second * n + l1.second;
      ans[p] = i;
    }
    else {
      for(auto j : seq[l1.first]) {
        int d = different(pos[j][0].first, pos[j][1].first, l1.first);
        iscol[d] = true;
      }
      for(auto j : seq[l2.first]) {
        int d = different(pos[j][0].first, pos[j][1].first, l2.first);
        isline[d] = true;
      }
      isline[l1.first] = true; iscol[l2.first] = true;
      int p = l2.second * n + l1.second;
      ans[p] = i;
    }
  }

  for(int i=0; i<n*n; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}


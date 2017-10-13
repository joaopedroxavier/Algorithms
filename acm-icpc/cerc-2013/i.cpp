#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 1e5+5;

vector<ii> ans;

void myswap(int l, int r, vector<int> &v, vector<int> &pos){
  int m = (l+r)/2, s = r-l+1;

  ans.pb(mp(l,r));
/*
  printf("antes: ");
  for(int p : pos) printf("%d ", p);
  printf("\n");
*/
  for(int p=l;p<=m;p++) swap(pos[v[p]], pos[v[p+s/2]]), swap(v[p], v[p+s/2]); 
/*
  printf("depois: ");
  for(int p : pos) printf("%d ", p);
  printf("\n");
*/
}

void tofront(int i, int l, int r, vector<int> &v, vector<int> &pos){
  if(l == r) return;

  int m = (l+r)/2, s = r-l+1;

  if(s%2 and pos[i] != l){
    tofront(i, l+1, r, v, pos);
    ans.pb(mp(l,l+1));
    swap(pos[v[l]], pos[v[l+1]]), swap(v[l], v[l+1]);
  }

  else{
    if(pos[i] > m) myswap(l, r, v, pos); 
    tofront(i, l, m, v, pos);
  }

}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    ans.clear();

    vector<int> v(n), pos(n+1);
    for(int i=0;i<n;i++) scanf("%d", &v[i]), pos[v[i]] = i;

    for(int i=1;i<=n;i++) tofront(i, i-1, n-1, v, pos);
    printf("%d\n", (int)ans.size());
    for(ii p : ans) printf("%d %d\n", p.first+1, p.second+1);
  }

  return 0;
}

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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, v[N];
ll ans;
map<int, int> size;
map<int, int> key;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%d", &v[i]);

  size[1]++;
  key[1] = v[0];

  int p = 1;
  for(int i=1; i<n; i++) {
    if(v[i] != v[i-1]) {
      key[++p] = v[i];
      size[p]++;
    }
    else {
      size[p]++;
    }
  }

  set<ii> pq;
  set<int> sg;
  for(int i=1; i<=p; i++){ pq.insert({-size[i], i}); sg.insert(i); }
  while(!pq.empty()){

    /*
    for(auto i : sg) printf("%d ", i);
    printf("\n");
    */

    ii u = *pq.begin();
    int s = u.second;
    pq.erase(u);

    auto it = sg.find(s);
    if(it != sg.begin() and it != prev(sg.end())) {
      it--;
      auto lf = *it;
      it++; it++;
      auto rt = *it;
      it--;


      if(key[lf] == key[rt]) {
        pq.erase({-size[lf], lf});
        pq.erase({-size[rt], rt});

        sg.erase(lf);
        sg.erase(rt);

        size[lf] += size[rt];

        sg.insert(lf);

        pq.insert({-size[lf], lf});
      }
    }
    sg.erase(s);
    ans++;
  }

  printf("%lld\n", ans);

  return 0;
}


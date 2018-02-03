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
typedef pair<int, ii> iii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vector<ii> pi;
map<int, vector<ii>> ord;
map<int, vector<ii>> ans;
map<ii, int> pos;
map<ii, int> type;
int n, w, h;

bool cmp(ii a, ii b) {
  if (type[a] != type[b]) return type[a] < type[b];
  else {
    if(type[a] == 1) return a.first < b.first;
    else return a.second > b.second;
  }
}

int main(){
  scanf("%d %d %d", &n, &w, &h);

  for(int i=0;i<n;i++){
    int d, p, w;
    scanf("%d %d %d", &d, &p, &w);
    if(d == 1){
      pi.pb(mp(p,-w));
      ord[p-w].pb(mp(p,-w));
      type[mp(p,-w)] = d;
    }
    else{
      pi.pb(mp(-w,p));
      ord[p-w].pb(mp(-w,p));
      type[mp(-w,p)] = d;
    }
  }

  for(auto it : ord) {
//    for(ii p : it.second) printf("%d %d\n", p.first, p.second);
//    printf("\n");
  }

  for(auto it : ord) {
    sort(it.second.begin(), it.second.end());

    int ct=0;
    for(ii p : it.second) pos[p] = ct++;

    sort(ord[it.first].begin(), ord[it.first].end(), cmp);
//    for(ii p : ans[it.first]) printf("%d %d\n", p.first, p.second);
//    printf("\n");
  }

  for(ii p : pi) {
    int x = p.first, y = p.second;
    ii ansp = ord[x+y][pos[p]];
    if(type[ansp] == 1) ansp.second = h;
    else ansp.first = w;
    printf("%d %d\n", ansp.first, ansp.second);
  }

	return 0;
}


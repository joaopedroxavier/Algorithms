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

int vis[N], a[N], id[N];
vi aux;
vector<vi> ans;

void fill(int u){
  vis[u] = 1;
  aux.pb(u);
  if(!vis[id[u]]) fill(id[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &a[i]);
    id[i] = i;
  }

  sort(id+1, id+n+1, [](int i, int j){ return a[i] < a[j] ; });

  for(int i=1;i<=n;i++) if(!vis[i]){
    aux.clear();
    fill(i);
    ans.pb(aux);
  }

  printf("%d\n", (int)ans.size());
  for(vi v : ans){
    printf("%d ", (int)v.size());
    for(int i=0;i<(int)v.size()-1;i++) printf("%d ", v[i]);
    printf("%d\n", v[v.size()-1]);
  }

	return 0;
}


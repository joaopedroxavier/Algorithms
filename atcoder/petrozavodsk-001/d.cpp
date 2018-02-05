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
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m;
map<int, int> cur_tree;
map<int, set<int>> tree;
map<int, multiset<ll>> available;
set<ll> leaves;
multiset<pll> trees_cost;
ll totalcost, cst[N];

void merge(int a, int b, bool cut) {
  //printf("merging trees rooted in %d and %d\n", a, b);
  if(tree[a].size() > tree[b].size()) swap(a, b);

  for(auto i : tree[a]) {
    cur_tree[i] = b;
    tree[b].insert(i);
  }

  //printf("nodes in the tree %d were passed to tree %d\n", a, b);
  //printf("tree %d has: ", b);
  /*
  for(auto i : tree[b]) {
    printf("%d ", i);
  }
  */

  ll bckb = *(available[b].begin()), bcka = *(available[a].begin());
  //printf("cost: %lld\n", bcka + bckb);

  if(cut) totalcost += bcka + bckb;

  if(cut) { available[a].erase(available[a].begin()), available[b].erase(available[b].begin()); }

  for(auto i : available[a]) {
    available[b].insert(i);
  }

  tree.erase(a);
  available.erase(a);
  trees_cost.erase(mp(bcka, a));
  trees_cost.erase(mp(bckb, b));
  if(cut and available[b].empty()) tree.erase(b), available.erase(b);

  if(tree.count(b)) {
    trees_cost.insert(mp(*available[b].begin(), b));
  }
}

int main(){
  scanf("%d %d", &n, &m);
  if(n == 1) return printf("0\n"), 0;

  for(int i=0; i<n; i++) {
    scanf("%lld", &cst[i]);
    available[i].insert(cst[i]);
    tree[i].insert(i);
    cur_tree[i] = i;
    trees_cost.insert(mp(cst[i], i));
  }

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = cur_tree[u], v = cur_tree[v];
    merge(u, v, false);
  }

  /*
  printf("I'm calculating...\n");
  printf("my forest is:\n");
  for(auto i : tree) {
    printf("- a tree rooted on %d and with available nodes: ", i.first);
    for(auto j : i.second) printf("%d ", j);
    printf("\n");
  }
  */

  for(auto i : tree) {
    if(i.second.size() == 1) leaves.insert(i.first);
  }

  for(auto i : leaves) tree.erase(i);

  while(tree.size() > 1) {
    /*
    printf("In this step, the following nodes are available: ");
    for(auto i : tree) {
      for(auto j : available[i.first]) {
        printf("%d ", j);
      }
    }
    printf("\n");
    */
    auto it = trees_cost.begin();
    pll p1 = *it;
    it++;
    pll p2 = *it;

    ll a = p1.second, b = p2.second;
    if(available[a].empty() or available[b].empty()) return printf("Impossible\n"), 0;
    merge(a, b, true);
  }

  if(tree.empty()) return printf("Impossible\n"), 0;
  int root = (tree.begin())->first;
  for(auto i : leaves) {
    if(available[root].size()) {
      ll p = *available[root].begin();
      totalcost += p + cst[i];
    }
    else return printf("Impossible\n"), 0;
  }

  printf("%lld\n", totalcost);

  return 0;
}

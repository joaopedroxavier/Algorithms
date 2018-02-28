#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct cand {
  int total, id;
  vector<int> votes;

  bool operator<(cand c) const {
    if(total != c.total) return total > c.total;

    for(int i=0; i < (int) votes.size(); i++) if(votes[i] != c.votes[i]) {
      return votes[i] > c.votes[i];
    }

    return id < c.id;
  }

  bool operator==(cand c) const { 
    if(total != c.total) return false;

    for(int i=0; i < (int) votes.size(); i++) if(votes[i] != c.votes[i]) {
      return false;
    }

    return true;
  }
};

bool valid(int u, int k, int j, int v) { return u <= k and u >= 1 and j < v; }

int t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d", &t);

  for(int q=0; q<t; q++) {
    int n, k, v;
    scanf("%d %d %d", &n, &k, &v);

    vector<cand> candidates(k);
    for(int i=0; i<k; i++) {
      candidates[i].votes.resize(v);
      for(int j=0; j<v; j++) candidates[i].votes[j] = 0;
      candidates[i].id = i;
    }

    for(int i=0; i<n; i++) {
      int s; scanf("%d", &s);
      for(int j=0; j<s; j++) {
        int u; scanf("%d", &u);
        if(valid(u, k, j, v)) candidates[u-1].votes[j]++, candidates[u-1].total++;
      }
    }

    sort(candidates.begin(), candidates.end());

    vector<int> ans;
    for(int i=0; i<v; i++) ans.push_back(candidates[i].id);

    /*
    for(int i=0; i<k; i++) {
      printf("candidate %d:\n", candidates[i].id);
      for(int j : candidates[i].votes) printf("%d ", j);
      printf("\n");
    }
    */

    cand last = candidates[v-1];
    for(int i=v; i < (int) candidates.size() and candidates[i] == last; i++) ans.push_back(candidates[i].id);

    for(int i : ans) printf("%d ", i+1);
    printf("\n");
  }

	return 0;
}


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


unordered_map<string, int> cnt; 
unordered_map<string, int> idx;
vector<string> cand;
vector<string> ans;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  ans.resize(n);

  vector<string> v(n);
  for(int i=0; i<n; i++) cin >> v[i];

  for(int t=1; t<=9; t++) {
    for(int i=0; i<n; i++) {
      set<string> st;
      for(int l=0; l<=9-t; l++) {
        string s = v[i].substr(l, t);
        //printf("%s\n", s.c_str());
        if(!cnt[s]) cand.pb(s);
        idx[s] = i;
        if(!st.count(s)) cnt[s]++, st.insert(s);
      }
    }
  }

  for(string s : cand){
    //printf("%s\n", s.c_str());
    if(cnt[s] == 1){
      int id = idx[s];
      if(ans[id].empty()) ans[id] = s;
    }
  } 

  for(string s : ans) printf("%s\n", s.c_str());

  return 0;
}


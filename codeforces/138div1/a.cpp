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

int pref[N], go[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = (int) s.size();
  pref[0] = (s[0] == '[');
  for(int i=1; i<n; i++) pref[i] = pref[i-1] + (s[i] == '[');

  stack<pair<char, int>> st;
  for(int i=0; i<n; i++) {
    if(s[i] == '(') st.push(mp(s[i], i));
    if(s[i] == '[') st.push(mp(s[i], i));
    if(s[i] == ']') {
      if(!st.empty() and st.top().first == '[') {
        go[st.top().second] = i;
        st.pop();
      }
      else {
        st.push(mp(s[i], i));
      }
    }
    if(s[i] == ')') {
      if(!st.empty() and st.top().first == '(') {
        go[st.top().second] = i;
        st.pop();
      }
      else {
        st.push(mp(s[i], i));
      }
    }
  }

  int ans = 0;
  int l = 0, r = 0;
  int ansl = 0, ansr = 0;
  for(int i=0; i<n; i++) {
    if(go[i]) {
      l = i;
      i = go[i];
      while(go[i+1]) i = go[i+1];
      r = i;
      if(pref[r] - pref[l-1] > ans) {
        ans = pref[r] - pref[l-1];
        ansl = l, ansr = r;
      }
    }
  }

  printf("%d\n", ans);
  if(ansr-ansl >= 1) for(int i=ansl; i<=ansr; i++) printf("%c", s[i]);
  printf("\n");
  return 0;
}


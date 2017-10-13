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

string numb, ans;

bool poss(vi used, int t, bool eq){
  int i = eq ? numb[t] - '0' : 9;
  for(; i>=0; i--){
    if(used[i] < 2){
      if(t == (int) numb.size() - 1){
        ans[t] = i + '0';
        return true;
      }

      used[i]++;
      if(poss(used, t+1, eq and i == numb[t] - '0')){
        ans[t] = i + '0';
        return true;
      }
      used[i]--;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> numb;
  ans.resize(numb.size());

  vi used(10, 0);
  poss(used, 0, true);

  bool lz = true;
  for(int i=0; i<(int)ans.size(); i++){
    lz = lz and ans[i] == '0';
    if(!lz) cout << ans[i];
  }
  cout << endl;

  return 0;
}


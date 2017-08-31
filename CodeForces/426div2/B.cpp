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

int n, k;
string ent;
map<char, int> fst, lst;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cin >> ent;

  for(int i=0;i<26;++i){
    fst['A'+i] = lst['A'+i] = INF;
    int p = 0;
    for(char c : ent){
      if(c == 'A'+i){
        if(fst[c] == INF) fst[c] = p;
        lst[c] = p;
      }
      p++;
    }
  }

  int s = ent.size(), sum=0;
  for(int i=0;i<s;++i){
    if(fst[ent[i]] == i) sum++;
    if(sum > k){
      cout << "YES" << endl;
      return 0;
    }
    if(lst[ent[i]] == i) sum--;
  }

  cout << "NO" << endl;
  return 0;
}


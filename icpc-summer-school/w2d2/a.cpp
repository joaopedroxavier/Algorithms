#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<ll, ll> terms;
int n;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    char c; ll x;
    scanf(" %c %lld", &c, &x);
    if(c == '+') {
      terms[x]++;
    }
    else {
      terms[x]--;
      if(!terms[x]) terms.erase(x);
    }

    ld accum = 1, avg = 0;
    int step = 0;
    if(terms.empty()) printf("0.000000000000\n");
    else {
      for(auto i : terms) {
        ld num  = (ld) i.first;
        ld num2 = (ld) (i.second);
        ld den  = (ld) (i.second + 1);

        avg += (num2 * num / (den)) / accum ;
        accum *= den;
        step++;
        if(step >= 50) break;
      }
      avg *= accum;
      avg /= (accum-1);
      printf("%.12Lf\n", avg);
    }
  }

  return 0;
}


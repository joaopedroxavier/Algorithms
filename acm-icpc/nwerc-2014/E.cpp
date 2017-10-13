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
const ld ETL = 1e-6;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ld n, v, p, s;
ld ans1, ans2;

ld func(ld x){
  return (n * pow(log2(n), x * sqrt(2)) / (p * 1e9)) + ((1 + 1 / x) * s / v);
}

void ternarySearch(){
  ans1 = (ld)0, ans2 = (ld)100;

  while((ans2 - ans1) > ETL or (ans2 - ans1) / ans2 > ETL){
    ld m1 = (2*ans1 + ans2) / 3;
    ld m2 = (ans1 + 2*ans2) / 3;
    if(func(m1) < func(m2)) ans2 = m2; else ans1 = m1;
  }

  printf("%.12Lf %.12Lf\n", func(ans2), ans2);
}

int main(){
  scanf("%Lf %Lf %Lf %Lf", &n, &p, &s, &v);
  ternarySearch();
	return 0;
}


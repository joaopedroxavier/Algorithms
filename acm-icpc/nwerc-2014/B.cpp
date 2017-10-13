#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define fst first
#define snd second
#define y1 ashduasiugd

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ld dist(ld px1, ld py1, ld px2, ld py2){ return sqrt((px2-px1)*(px2-px1) + (py2-py1)*(py2-py1)); }

int n;
ld x1, y1, x2, y2;
ld vwalk, vbike, ans = 1e9;
ld hborder, vborder;
ld xg, yg, xd, yd;
ld x[N], y[N];

pair<ld, ld> to_board(int f, ld m){
  if(f == 1) return mp(0, m);
  if(f == 2) return mp(hborder, m);
  if(f == 3) return mp(m, 0);
  if(f == 4) return mp(m, vborder);
  return mp(INF, INF);
}

ld cost(pair<ld, ld> p1, pair<ld, ld> p2, ld v1, ld v2){
  return (dist(xg, yg, p1.fst, p1.snd) / v1) + (dist(p1.fst, p1.snd, p2.fst, p2.snd) / v2) + (dist(p2.fst, p2.snd, xd, yd) / v1); 
}

ld ternarysearch(ld l, ld r, pair<ld, ld> p1, int f, ld v1, ld v2){
  while(abs(r-l) > EPS){
    ld m1 = (2*l + r)/3, m2 = (l + 2*r)/3;
    pair<ld, ld> pm1 = to_board(f, m1), pm2 = to_board(f, m2);

    ans = min(ans, min(cost(p1, pm1, v1, v2), cost(p1, pm2, v1, v2)));

    if(cost(p1, pm1, v1, v2) > cost(p1, pm2, v1, v2)) l = m1;
    else r = m2;
  }
  return (r+l)/2; 
}

ld ternarysearch2(ld l, ld r, pair<ld, ld> p1, int f, ld v1, ld v2){
  while(abs(r-l) > EPS){
    ld m1 = (2*l + r)/3, m2 = (l + 2*r)/3;
    pair<ld, ld> pm1 = to_board(f, m1), pm2 = to_board(f, m2);

    ans = min(ans, min(cost(pm1, p1, v1, v2), cost(pm2, p1, v1, v2)));

    if(cost(pm1, p1, v1, v2) > cost(pm2, p1, v1, v2)) l = m1;
    else r = m2;
  }
  return (r+l)/2; 
}

ld ternarySearch_nest(ld l, ld r, int f1, int f2, ld v1, ld v2){
  while(abs(r-l) > EPS){
    ld m1 = (2*l + r)/3, m2 = (l + 2*r)/3;
    pair<ld, ld> pm1 = to_board(f1, m1), pm2 = to_board(f1, m2);
    if(f2 <= 2){
      pair<ld, ld> bestm1 = to_board(f2, ternarysearch(0, vborder, pm1, f2, v1, v2));
      pair<ld, ld> bestm2 = to_board(f2, ternarysearch(0, vborder, pm2, f2, v1, v2));

      ans = min(ans, min(cost(pm1, bestm1, v1, v2), cost(pm2, bestm2, v1, v2)));

      if(cost(pm1, bestm1, v1, v2) > cost(pm2, bestm2, v1, v2)) l = m1;
      else r = m2;
    }
    else{
      pair<ld, ld> bestm1 = to_board(f2, ternarysearch(0, hborder, pm1, f2, v1, v2));
      pair<ld, ld> bestm2 = to_board(f2, ternarysearch(0, hborder, pm2, f2, v1, v2));

      ans = min(ans, min(cost(pm1, bestm1, v1, v2), cost(pm2, bestm2, v1, v2)));

      if(cost(pm1, bestm1, v1, v2) > cost(pm2, bestm2, v1, v2)) l = m1;
      else r = m2;
    }
  }
  return (r+l)/2;
}

int main(){
  scanf("%Lf %Lf", &vwalk, &vbike);
  scanf("%Lf %Lf %Lf %Lf", &x1, &y1, &x2, &y2);
  hborder = x2-x1, vborder = y2-y1;
  scanf("%Lf %Lf", &xg, &yg);
  scanf("%Lf %Lf", &xd, &yd);
  xg -= x1, yg -= y1, xd -= x1, yd -= y1;
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%Lf %Lf", &x[i], &y[i]);
    x[i] -= x1, y[i] -= y1;
  }
  //for(int i=0;i<n;i++) printf("%.9Lf %.9Lf\n", x[i], y[i]);

  for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(j != i){
    ans = min(ans, cost(mp(x[i], y[i]), mp(x[j], y[j]), vwalk, vbike));
  }

  for(int i=0;i<n;i++){
    for(int f=1;f<=4;f++){
      if(f <= 2){
        ternarysearch(0, vborder, mp(x[i], y[i]), f, vwalk, vbike);
        ternarysearch2(0, vborder, mp(x[i], y[i]), f, vwalk, vbike);
      }
      else{
        ternarysearch(0, hborder, mp(x[i], y[i]), f, vwalk, vbike);
        ternarysearch2(0, hborder, mp(x[i], y[i]), f, vwalk, vbike);
      }
    }
  }

  for(int f=1;f<=4;f++) for(int f2=1;f2<=4;f2++){
    if(f <= 2){
      ternarySearch_nest(0, vborder, f, f2, vwalk, vbike);
    }
    else{
      ternarySearch_nest(0, hborder, f, f2, vwalk, vbike);
    }
  }

  printf("%.9Lf\n", min(ans, dist(xg, yg, xd, yd) / vwalk));
	return 0;
}


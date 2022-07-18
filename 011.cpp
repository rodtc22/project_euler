#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

template <typename A,typename B> ostream& operator <<(ostream& os, pair<A,B>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template <typename T> ostream& operator <<(ostream& os, vector<T>& v) {    os << "[" ;    for(int i = 0 ;i < v.size(); i++){      if(i) os <<", ";      os <<v[i];    }    os << "]";return os;}
template <typename T> istream& operator >>(istream& is, vector<T>& v){ for(auto &x : v) is >> x; return is;}
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
const int inf = 2e9;
const int mod = 1e9+7;
const int N = 2e6;

void printe(){}
template <typename H, typename ...T>
void printe(H x, T... y){
   cout << ", " << x;
   printe(y...);
}

#define er(args...) { cout << "DBG: " << #args << " {"; printe(args); cout << "}\n"; } 

int di[] = {-1,-1,-1,0,0,1,1,1};
int dj[] = {-1,0,1,-1,1,-1,0,1};

bool isvalid(int x, int n){return 0 <= x && x < n;}

int main(){
   int n = 20;
   int grid[n][n];
   for(int i = 0 ;i < n; i++) for(int j = 0 ;j < n ;j++) cin >> grid[i][j];

   ll ans = 0;
   for(int i = 0 ;i < n ;i++){
      for(int j = 0 ;j < n; j++){
         for(int k = 0 ; k < 8 ;k++){
            bool sw = true;
            ll acu = grid[i][j];
            int newi = i, newj = j ;
            for(int l = 0 ; l < 3 ; l++){
               newi += di[k];newj += dj[k];

               if(isvalid(newi,n) && isvalid(newj,n)){
                  acu *= grid[newi][newj];
               }else{
                  sw = false;
               }
            }
            
            if(sw) ans = max(ans,acu);
         }
      }
   }
   cout << ans << endl;
   return 0;
}
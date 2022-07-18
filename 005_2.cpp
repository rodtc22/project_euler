#include <iostream>
#include <algorithm>
#include <cmath>
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
const int N = 1e6;

//learning variadic functions :D
void print(){cout  <<"}"<<  endl;}
template <typename T, typename... Types>
void print(T x,Types ...args){
   cout << " " << x;
   print(args...);
}
#define error(args...) {cout <<"DBG: "<< #args << " = {";print(args);}

// p[i] ^ expo[i]

int n = 8;
vector<int> primo = {2,3,5,7,11,13,17,19};
vector<int> expo(8,0);


/*PODEMOS SACAR LA FACTORIZACION DE UN NUMERO, RECORRIENDO TODOS LOS PRIMOS QUE LO DIVIDEN
Y VIENDO CUAL ES EL EXPONENTE DE ESE FACTOR, CON log(base=k,nro=N) */
void sacarFactorizacion(int x){
   for(int i= 0 ;i < n; i++) {
      int m = floor(log(x)/log(primo[i])); //log_k(N)  = log(N)/log(k)
      expo[i] = max(expo[i],m);
   }
}

int main(){

   //sacando lcm de 2 a 20
   for(int i= 1 ;i <= 10;i++)
      sacarFactorizacion(i);

   int ans = 1;
   for(int i= 0 ;i < n;i++){
      for( ; expo[i] ; expo[i]--)
         ans *= primo[i];
   }
   cout << ans << endl;
   return 0;
}
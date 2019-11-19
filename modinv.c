/*
整数aの、mに対する逆元を求める関数。
問題：AtCoder ABC145-D

(使用例)
入力：2 13　
出力：7
(2*7=14=1(mod 13)なので)
*/


/*
入力：long型2つ
出力：long型
*/


#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

//a*x + MOD*y = 1の整数解を求める。その中で最小の正数xがaの逆元となる。
//解き方は、ユークリッドの互除法
//参考：http://arc360.info/algo/privatekey.html
long modinv(long a, long m) {
  long b = m, u = 1, v = 0;
  while (b) {
    long t = a / b;
    a -= t * b; SWAP(long,a, b);
    u -= t * v; SWAP(long,u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}


int main(void){
    long a,mod;
    scanf("%ld%ld",&a,&mod);

    long ans=modinv(a,mod);
    printf("%ld\n",ans);

    return 0;
}
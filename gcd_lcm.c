/*
a, bの最大公約数・最小公倍数を求める
問題：AtCoder ABC131-C

(使用例)
gcd
入力：6 8
出力：2

lcm
入力：6 8
出力：24
*/


/*
使用データ構造
int gcd(int a, int b)
int lcm(int a, int b)

入力：int2個(0わりは入力時に避ける、abの大小は気にしなくて良い)
出力：int
*/

#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//最大公約数
int gcd(int a, int b){
    //a>bになるように入れ替え
    if(a<b){
        int tmp=a;
        a=b;
        b=tmp;
    }

    //ユークリッドの互除法
    if(a%b==0) return b;
    return gcd(b,a%b);
}

//最小公倍数
int lcm(int a, int b){
    return a*(b/gcd(a,b));
}

//以下のmain関数に、(使用例)と同じ入力をすることで動作を(同時)確認できる。
int main(void){
    int a, b;
    scanf("%d %d",&a,&b);

    int GCD=gcd(a,b);
    int LCM=lcm(a,b);
    
    printf("%d %d\n",GCD,LCM);


    return 0;
}
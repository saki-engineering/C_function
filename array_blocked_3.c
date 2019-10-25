/*
文字列が与えられた時に、同じ要素が続く群列に変換する関数を導入する。
問題：AtCoder ABC124-D

(使用例)
入力：5 00010
出力：
char 0 num 3 begin 0 end 2
char 1 num 1 begin 3 end 3
char 0 num 1 begin 4 end 4
*/


/*
使用データ構造
void array_blocked_3(char* S, int N, block* A)

導入：構造体block型

入力：配列(文字列)　S[0]~S[N-1]、　文字列長さN, ブロック中の要素数を格納する配列A
出力：なし
*/

#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int n; //ブロック中の文字数
    char c; //ブロックの文字
    int begin; //ブロック開始場所の添字
    int end; //ブロック終了場所の添字
}block;

void array_blocked_3(char* S, int N, block* A){
    int a=0;
    int count=1;

    A[a].begin=0;

    for(int i=1;i<N;i++){
        if(S[i-1]==S[i]){
            count++;
        }
        else{
            A[a].n=count;
            A[a].c=S[i-1];
            A[a].end=i-1;
            a++;
            A[a].begin=i;
            count=1;
        }
    }
    A[a].n=count;
    A[a].c=S[N-1];
    A[a].end=N-1;
    return;
}

//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。

int main(void){
    int N;
    scanf("%d",&N);

    char S[N+1];
    scanf("%s",S);

    block* B;
    NEW(B,N+1);
    array_blocked_3(S,N,B);

    //ブロックの数
    int blo=0;
    while(B[blo].n!=0){
        printf("char %c num %d begin %d end %d\n",B[blo].c, B[blo].n, B[blo].begin, B[blo].end);
        blo++;
    }

    return 0;
}
/*
文字列が与えられた時に、同じ要素が続く群列に変換する関数を導入する。
問題：AtCoder ABC137-C

(使用例)
入力：abbcccdddd
出力：1 2 3 4(配列)
*/


/*
使用データ構造
void array_blocked_2(String S, int* A)

導入：String型

入力：配列(文字列)　S[0]~S[N-1]、　ブロック中の要素数を格納する配列A
出力：なし
*/

#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;

//S[0]から始まる文字列の長さを求める関数
int string_len(String str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

//文字列を標準入力から読み込み、それをString型のメモリを確保し直してくれる関数
//S[0]~S[n-1]までが入力で、S[n]は0になる
//文字列長さの上限は1000まで
String string_input(void){
    int i,len;
    char buf[1000];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=string_len(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}

void array_blocked_2(String S, int* A){
    int N=string_len(S);
    int a=0;
    int count=1;

    for(int i=1;i<N;i++){
        if(S[i-1]==S[i]){
            count++;
        }
        else{
            A[a]=count;
            a++;
            count=1;
        }
    }
    A[a]=count;
    return;
}

//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    String S=string_input();
    int* A;
    NEW(A,1000); //ここの1000は仮、つまり1000個までのブロックを数えられる

    array_blocked_2(S,A);
    
    int i=0;
    while(A[i]!=0){
        printf("%d ",A[i]);
        i++;
    }
    printf("\n");
}
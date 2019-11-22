/*
長さがわからない文字列を標準入力から取り込む関数を導入する。
問題：AtCoder ABC141-B

(使用例)
入力：RUDLUDR
出力：
*/


/*
使用データ構造
String string_input(void)

導入：String型(charポインタ)

入力：なし
出力：String型
*/





#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;

//S[0]から始まる文字列の長さを求める関数
//→string.hのstrlen関数でOK
/*
int string_len(String str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}
*/

//文字列を標準入力から読み込み、それをString型のメモリを確保し直してくれる関数
//S[0]~S[n-1]までが入力で、S[n]は0になる
//文字列長さの上限は1000まで
String string_input(void){
    int i,len;
    char buf[1000];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=strlen(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}



//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    String S=string_input();

    int N=strlen(S);
    printf("%d\n",N);
    for(int i=0;i<N;i++){
        printf("%c",S[i]);
    }
    printf("\n");

    return 0;
}
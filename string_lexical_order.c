/*
文字列が与えられた時に、それを前から辞書順になるようにソートする
問題：AtCoder ABC137-C

(使用例)
入力： oneplustwo
出力：elnoopstuw(前から辞書順)
*/


/*
使用データ構造
void string_lexical_order(String s)

導入：String型

入力：String型文字列S[0]~S[N-1]
出力：なし
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;


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

void string_lexical_order(String s){
    int n = strlen(s);

    //挿入法でのソートを行う
    int i,j;
    for(i=0;i<n;i++){
        char c=s[i]; //これからこの文字(s[i])の挿入場所を探す
        for(j=i-1;j>=0&&s[j]>c;j--){ //探す範囲はs[i-1]~s[0]
            s[j+1]=s[j]; //ここじゃないなと思ったら、後ろにずらしていく
        }
        if(j!=i-1){
            s[j+1]=c; //挿入場所に入れる
        }
    }
    return;
}

//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。
int main(void){
    String S=string_input();
    string_lexical_order(S);
    printf("%s\n",S);
    return 0;
}
/*
文字列が与えられた時に、それを前から辞書順になるようにソートする
問題：AtCoder ABC137-C

(使用例)
入力： oneplustwo abaaaaaaaa
出力：1(前者の方が後者より辞書順が後だから)
*/


/*
使用データ構造
int string_compare(String p,String q)

導入：String型

入力：String型文字列S[0]~S[N-1]2個
出力：int整数(0,-1,1)
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

//与えられた文字列を比較し、結果によって決められたint型変数を返す関数
//p<qなら-1,p>qなら+1,p==qなら0
int string_compare(String p,String q){
    int np=string_len(p);
    int nq=string_len(q);

    int m;
    if(np<=nq) m=np;
    else m=nq;
    //mは、文字列p,qのうち短い方の長さを表すint型変数
    
    int i=0;
    int n=0;
    while(i<=m){
        if(p[i]<q[i]){n=-1; break;}
        else if(p[i]>q[i]){n=1; break;}
        else{i++;}
    }
    
    return n;
}

//qsortに使うのはこれ
int string_compare２(const void* a, const void* b){
    String p=*(String*)a;
    String q=*(String*)b;
    
    int np=string_len(p);
    int nq=string_len(q);

    int m;
    if(np<=nq) m=np;
    else m=nq;
    //mは、文字列p,qのうち短い方の長さを表すint型変数
    
    int i=0;
    int n=0;
    while(i<=m){
        if(p[i]<q[i]){n=-1; break;}
        else if(p[i]>q[i]){n=1; break;}
        else{i++;}
    }
    
    return n;
}


//以下のmain関数に、(使用例)と同じ入力をすることで動作を確認できる。

int main(void){
    String S1,S2;
    S1=string_input();
    S2=string_input();

    int ans=string_compare(S1,S2);
    printf("%d\n",ans);
}
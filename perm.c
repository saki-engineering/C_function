#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define N 5

int buffer[N];
int used[N];

void make_perm(int n, int size){
    if (n == size){
        for(int i = 0; i < size; i++) printf("%d ", buffer[i]);
        printf("\n");
    }
    else {
        for (int i = 0; i < size; i++) {
            if (used[i]) continue;
            buffer[n] = i;
            used[i] = 1;
            make_perm(n + 1, size);
            used[i] = 0;
        }
    }
}

int main(void){
    make_perm(0,N);
    return 0;
}

/*
出力が
0 1 2 3 4 
0 1 2 4 3 
0 1 3 2 4 
0 1 3 4 2 
0 1 4 2 3 
0 1 4 3 2 
0 2 1 3 4 
0 2 1 4 3 
0 2 3 1 4 
0 2 3 4 1 
0 2 4 1 3 
0 2 4 3 1 
0 3 1 2 4 
0 3 1 4 2 
0 3 2 1 4 
0 3 2 4 1 
0 3 4 1 2 
0 3 4 2 1 
0 4 1 2 3 
0 4 1 3 2 
0 4 2 1 3 
0 4 2 3 1 
0 4 3 1 2 
0 4 3 2 1 
1 0 2 3 4 
1 0 2 4 3 
1 0 3 2 4 
1 0 3 4 2 
1 0 4 2 3 
1 0 4 3 2 
1 2 0 3 4 
1 2 0 4 3 
1 2 3 0 4 
1 2 3 4 0 
1 2 4 0 3 
1 2 4 3 0 
1 3 0 2 4 
1 3 0 4 2 
1 3 2 0 4 
1 3 2 4 0 
1 3 4 0 2 
1 3 4 2 0 
1 4 0 2 3 
1 4 0 3 2 
1 4 2 0 3 
1 4 2 3 0 
1 4 3 0 2 
1 4 3 2 0 
2 0 1 3 4 
2 0 1 4 3 
2 0 3 1 4 
2 0 3 4 1 
2 0 4 1 3 
2 0 4 3 1 
2 1 0 3 4 
2 1 0 4 3 
2 1 3 0 4 
2 1 3 4 0 
2 1 4 0 3 
2 1 4 3 0 
2 3 0 1 4 
2 3 0 4 1 
2 3 1 0 4 
2 3 1 4 0 
2 3 4 0 1 
2 3 4 1 0 
2 4 0 1 3 
2 4 0 3 1 
2 4 1 0 3 
2 4 1 3 0 
2 4 3 0 1 
2 4 3 1 0 
3 0 1 2 4 
3 0 1 4 2 
3 0 2 1 4 
3 0 2 4 1 
3 0 4 1 2 
3 0 4 2 1 
3 1 0 2 4 
3 1 0 4 2 
3 1 2 0 4 
3 1 2 4 0 
3 1 4 0 2 
3 1 4 2 0 
3 2 0 1 4 
3 2 0 4 1 
3 2 1 0 4 
3 2 1 4 0 
3 2 4 0 1 
3 2 4 1 0 
3 4 0 1 2 
3 4 0 2 1 
3 4 1 0 2 
3 4 1 2 0 
3 4 2 0 1 
3 4 2 1 0 
4 0 1 2 3 
4 0 1 3 2 
4 0 2 1 3 
4 0 2 3 1 
4 0 3 1 2 
4 0 3 2 1 
4 1 0 2 3 
4 1 0 3 2 
4 1 2 0 3 
4 1 2 3 0 
4 1 3 0 2 
4 1 3 2 0 
4 2 0 1 3 
4 2 0 3 1 
4 2 1 0 3 
4 2 1 3 0 
4 2 3 0 1 
4 2 3 1 0 
4 3 0 1 2 
4 3 0 2 1 
4 3 1 0 2 
4 3 1 2 0 
4 3 2 0 1 
4 3 2 1 0 
*/
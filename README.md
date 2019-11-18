# C_function
私がよくAtCoderでよく使う関数をまとめました。<br>
以下、upしたファイルの一つである「general_tree.c」を元に見方を解説します。

## 概要
```C
/*
二分木とは限らない一般の木構造(子がいくつかが決まってない)を記述する
問題：AtCoder ABC138-D

(使用例)
入力：(上記問題の入力例1のグラフ)
4
1 2
2 3
2 4
出力：
node 1 parent null children 2 
node 2 parent 1 children 4 3 
node 3 parent 2 children 
node 4 parent 2 children 
*/
```
冒頭でこの関数が何の為に作られたのか、何ができるのかを一行で簡潔に説明。<br>
この時は[AtCoderのABC138 D問題](https://atcoder.jp/contests/abc138/tasks/abc138_d)を解くために作った。<br>
<br>
与えられていた状況は以下の通り。
>1からNまでの

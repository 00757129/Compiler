* 擴充前一步製作的編譯器，讓其不是只能接受像42這樣的值，而是可以輸入像 2+11或 5+20-4這種包含加減法計算的算式。

* 加法和減法的組合語言指令分別是add和sub。
* add會讀進兩個暫存器的值，執行加法後把結果寫回第1引數的暫存器內。
* sub和add基本上一樣，只是執行的是減法。
* 指令如下，先以mov指令把 RAX 設成5，再把 RAX 加上20，最後從中減去4，可以編譯5+20-4為：
```
.intel_syntax noprefix
.global main

main:
        mov rax, 5
        add rax, 20
        sub rax, 4
        ret
```
上述檔案存成 tmp.s 並組譯執行：
```
$ gcc -o tmp tmp.s
$ ./tmp
$ echo $?
21
```

make指令可以產生出新的執行檔。以下為執行的範例：
```
$ make
$ ./9cc '5+20-4'
.intel_syntax noprefix
.global main
main:
  mov rax, 5
  add rax, 20
  sub rax, 4
  ret
```

commit 到 git ,執行以下指令來 commit：
```
$ git add test.sh Compiler.c
$ git commit
```

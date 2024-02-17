# 執行指令:
```
$ gcc -o 9cc Compiler.c
$ ./Compiler 123 > tmp.s
```
第1行是編譯 Compiler.c 做出可執行的 9cc 檔案。

第二行是輸入123給 Compiler 來輸出組合語言，然後把結果寫進 tmp.s 這個檔案裡。

* tmp.s 的內容：
```
$ cat tmp.s
.intel_syntax noprefix
.global main
main:
  mov rax, 123
  ret
```

把 .s 副檔名的組合語言檔案輸入給 gcc，就會執行組譯。

以下就是執行組譯器：

```
$ gcc -o tmp tmp.s
$ ./tmp
$ echo $?
123
```

# 製作單元測試
以下就是名為 test.sh 的測試用 shell 腳本。

shell 函式try會從引數中把輸入值和預期的結果兩個引數抓下來、把9cc的結果拿去組譯、把結果和期待的值做比較。

在這個 shell 腳本中，定義完try之後，會用0和42兩個值來確認是否有正常編譯：
```
#!/bin/bash
try() {
  expected="$1"
  input="$2"

  ./9cc "$input" > tmp.s
  gcc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

try 0 0
try 42 42

echo OK
```
實際執行 test.sh 。

如果沒有出現什麼錯誤的話，如下最後 test.sh 會顯示 OK 並結束：
```
$ ./test.sh
0 => 0
42 => 42
OK
```
如果有發生錯誤的話，test.sh 不會顯示 OK，而是會顯示失敗的測試預期值和實際上的結果：
```
$ ./test.sh
0 => 0
42 expected, but got 123
```

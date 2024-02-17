#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引數數量錯誤\n");
    return 1;
  }
  //把項讀入
  char *p = argv[1];

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  //如果用atoi的話，因為atoi不會回傳所讀進的文字數目，所以用atoi會不知道要從哪裡開始讀取項。因此這邊使用C語言標準的strtol函式
  printf("  mov rax, %ld\n", strtol(p, &p, 10));

  //strtol函式在讀進數值之後，會更新第2引數的指標位置，指向讀進的最後一個文字的下一個文字
  //在讀進1個數值之後，如果下一個文字是+或-，p就應該是指向該文字。
  //在while迴圈中逐項讀取，每讀到1個項就輸出1行組合語言指令。
  while (*p) {
    if (*p == '+') {
      p++;
      printf("  add rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    if (*p == '-') {
      p++;
      printf("  sub rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "預料之外的文字: '%c'\n", *p);
    return 1;
  }

  printf("  ret\n");
  return 0;
}

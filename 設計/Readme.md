# 編譯器的構建流程
一般而言，編譯器的編寫分為 3 個步驟：

1. 詞法分析器，用於將字串轉化成內部的表示結構。
2. 語法分析器，將詞法分析得到的標記流（token）生成一棵語法樹。
3. 目標代碼的生成，將語法樹轉化成目標代碼。

* 所以我們會依照以下步驟來構建我們的編譯器：

1. 構建我們自己的虛擬機以及指令集。 這後生成的目標代碼便是我們的指令集。
2. 構建我們的詞法分析器
3. 構建語法分析器
4. 編譯器框架

# 主要包括4個函數：

* next() 用於詞法分析，獲取下一個標記，它將自動忽略空白字元。
* program() 語法分析的入口，分析整個 C 語言程式。
* expression(level) 用於解析一個表達式。
* eval() 虛擬機的入口，用於解釋目標代碼。

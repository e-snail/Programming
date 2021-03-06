##关于编码

#### utf-8
- unicode的实现方式之一
- 可变长度编码，使用1~4个字节
- 编码规则：
    - 单字节符号：字节的第一位设为0，后面的７位就是它的unicode码；所以，对于英文字母，UTF-8编码和ASCII编码是相同的。
    - n字节符号(n>1)： 第一个字节的前n位都设为1，第n+1位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。

举例： "汉"

其unicode码是`\u6c49`，转成二进制是 `110110001001001`

汉 在utf-8中需要用三个字节(通过查unicode表)表示，根据上述规则得到填充格式是 `111xxxxx 10xxxxxx 10xxxxxx`。

用6c49的二进制填充到以上格式中（从后往前，不足的以0补齐），得到：`11100110 10110001 10001001`，对应的十六进制表示：'E6 B1 89'。

这就是"汉"的utf-8，如果将"汉"放到url中，例如`http://t=汉`，就会被编码为：`http://t%3D%E6%B1%89`；`%E6%B1%89`，就是在utf-8码每个字节前加上%而已。

在windows上将"汉"存入文本，保存成不同格式，再用ultro-edit打开，以16进制显示，得到以下内容：

| | 汉 | 说明 | 
----|------|----
unicode LE | FF FE 49 6C | 小端存储，以FF FE开头，高位字节在高地址空间
unicode BE | FE FF 6C 49 | 大端存储，以FE FF开头，高位字节在低地址空间
utf-8 | EF BB BF E6 B1 89 | "EF BB BF"表示这是UTF-8编码
ANSI | BA BA | "汉"的GB2312编码


#### 参考文章
[字符编码笔记：ASCII，Unicode和UTF-8](http://www.ruanyifeng.com/blog/2007/10/ascii_unicode_and_utf-8.html)

## memset
``` C
#include<string.h>
void *memset(void *b, int c, size_t len)
```
将c拷贝到b前len长度中。
int类型尽量只赋值0和-1，因为memset赋值的时候是按字节赋值，所以会以二进制传递。
若str指向char型地址，value可为任意字符值；

查找字符串长度。
```C
size_t strlen(const char *__s)
```
size_t 为C中最大的长度（取决于你所使用的电脑和操作系统），无符号整数。

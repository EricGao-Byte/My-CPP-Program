#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;//直接复制字符串
    string s4(5, 's');
    //内置求字符串长度的函数
    //由于 string 的末尾没有'\0'字符，所以 length() 返回的是字符串的真实长度，而不是长度 +1。
    string s = "http://c.biancheng.net";
    int len = s.length();
    cout << len << endl;
	
    //虽然 C++ 提供了 string 类来替代C语言中的字符串，但是在实际编程中，有时候必须要使用C风格的字符串（例如打开文件时的路径），
    //为此，string 类为我们提供了一个转换函数 c_str()，该函数能够将 string 字符串转换为C风格的字符串，
    //并返回该字符串的 const 指针（const char* ）。请看下面的代码：
    string path = "D:\\demo.txt";
    FILE* fp = fopen(path.c_str(), "rt");

    //string 字符串也可以像C风格的字符串一样按照下标来访问其中的每一个字符。
    //string 字符串的起始下标仍是从 0 开始。请看下面的代码：
    string s = "1234567890";
    for (int i = 0, len = s.length(); i < len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    s[5] = '5';
    cout << s << endl;

    //有了 string 类，我们可以使用+或+=运算符来直接拼接字符串，非常方便，
    //再也不需要使用C语言中的 strcat()、strcpy()、malloc() 等函数来拼接字符串了，再也不用担心空间不够会溢出了。
    //用 + 来拼接字符串时，运算符的两边可以都是 string 字符串，也可以是一个 string 字符串和一个C风格的字符串，
    //还可以是一个 string 字符串和一个字符数组，或者是一个 string 字符串和一个单独的字符。请看下面的例子：
    string s1 = "first ";
    string s2 = "second ";
    const char* s3 = "third ";
    char s4[] = "fourth ";
    char ch = '@';
    string s5 = s1 + s2;
    string s6 = s1 + s3;
    string s7 = s1 + s4;
    string s8 = s1 + ch;
    cout << s5 << endl << s6 << endl << s7 << endl << s8 << endl;

    //insert() 函数可以在 string 字符串中指定的位置插入另一个字符串
    string s1, s2, s3;
    s1 = s2 = "1234567890";
    s3 = "aaa";
    //在s1第五个位置之后插入s3
    s1.insert(5, s3);
    cout << s1 << endl;
    s2.insert(5, "bbb");
    cout << s2 << endl;

    //erase() 函数可以删除 string 中的一个子字符串
    string s1, s2, s3;
    s1 = s2 = s3 = "1234567890";
    //删除字符串第五个字符后的所有字符,为12345
    s2.erase(5);
    //删除字符串第五个字符后的3个字符,为1234590
    s3.erase(5, 3);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    //substr() 函数用于从 string 字符串中提取子字符串
    string s1 = "first second third";
    string s2;
    s2 = s1.substr(6, 6);//为second
    cout << s1 << endl;
    cout << s2 << endl;

    //find() 函数用于在 string 字符串中查找子字符串出现的位置
    //第一个参数为待查找的子字符串，它可以是 string 字符串，也可以是C风格的字符串。第二个参数为开始查找的位置（下标）；
    //如果不指明，则从第0个字符开始查找。
    string s1 = "first second third";
    string s2 = "second";
    int index = s1.find(s2, 5);//为6
    //find() 函数最终返回的是子字符串第一次出现在字符串中的起始下标。本例最终是在下标6处找到了 s2 字符串。
    //如果没有查找到子字符串，那么会返回一个无穷大值 4294967295。
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;

    //rfind() 和 find() 很类似，同样是在字符串中查找子字符串，不同的是 find() 函数从第二个参数开始往后查找，
    //而 rfind() 函数则最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到子字符串，则返回一个无穷大值4294967295。
    string s1 = "first second third";
    string s2 = "second";
    int index = s1.rfind(s2, 6);//为6
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;

    //find_first_of() 函数用于查找子字符串和字符串共同具有的字符在字符串中首次出现的位置。
    string s1 = "first second second third";
    string s2 = "asecond";
    int index = s1.find_first_of(s2);//为3
    //本例中 s1 和 s2 共同具有的字符是 ’s’，该字符在 s1 中首次出现的下标是3，故查找结果返回3。
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;
	return 0;
}
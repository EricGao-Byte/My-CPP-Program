#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;//ֱ�Ӹ����ַ���
    string s4(5, 's');
    //�������ַ������ȵĺ���
    //���� string ��ĩβû��'\0'�ַ������� length() ���ص����ַ�������ʵ���ȣ������ǳ��� +1��
    string s = "http://c.biancheng.net";
    int len = s.length();
    cout << len << endl;
	
    //��Ȼ C++ �ṩ�� string �������C�����е��ַ�����������ʵ�ʱ���У���ʱ�����Ҫʹ��C�����ַ�����������ļ�ʱ��·������
    //Ϊ�ˣ�string ��Ϊ�����ṩ��һ��ת������ c_str()���ú����ܹ��� string �ַ���ת��ΪC�����ַ�����
    //�����ظ��ַ����� const ָ�루const char* �����뿴����Ĵ��룺
    string path = "D:\\demo.txt";
    FILE* fp = fopen(path.c_str(), "rt");

    //string �ַ���Ҳ������C�����ַ���һ�������±����������е�ÿһ���ַ���
    //string �ַ�������ʼ�±����Ǵ� 0 ��ʼ���뿴����Ĵ��룺
    string s = "1234567890";
    for (int i = 0, len = s.length(); i < len; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    s[5] = '5';
    cout << s << endl;

    //���� string �࣬���ǿ���ʹ��+��+=�������ֱ��ƴ���ַ������ǳ����㣬
    //��Ҳ����Ҫʹ��C�����е� strcat()��strcpy()��malloc() �Ⱥ�����ƴ���ַ����ˣ���Ҳ���õ��Ŀռ䲻��������ˡ�
    //�� + ��ƴ���ַ���ʱ������������߿��Զ��� string �ַ�����Ҳ������һ�� string �ַ�����һ��C�����ַ�����
    //��������һ�� string �ַ�����һ���ַ����飬������һ�� string �ַ�����һ���������ַ����뿴��������ӣ�
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

    //insert() ���������� string �ַ�����ָ����λ�ò�����һ���ַ���
    string s1, s2, s3;
    s1 = s2 = "1234567890";
    s3 = "aaa";
    //��s1�����λ��֮�����s3
    s1.insert(5, s3);
    cout << s1 << endl;
    s2.insert(5, "bbb");
    cout << s2 << endl;

    //erase() ��������ɾ�� string �е�һ�����ַ���
    string s1, s2, s3;
    s1 = s2 = s3 = "1234567890";
    //ɾ���ַ���������ַ���������ַ�,Ϊ12345
    s2.erase(5);
    //ɾ���ַ���������ַ����3���ַ�,Ϊ1234590
    s3.erase(5, 3);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    //substr() �������ڴ� string �ַ�������ȡ���ַ���
    string s1 = "first second third";
    string s2;
    s2 = s1.substr(6, 6);//Ϊsecond
    cout << s1 << endl;
    cout << s2 << endl;

    //find() ���������� string �ַ����в������ַ������ֵ�λ��
    //��һ������Ϊ�����ҵ����ַ������������� string �ַ�����Ҳ������C�����ַ������ڶ�������Ϊ��ʼ���ҵ�λ�ã��±꣩��
    //�����ָ������ӵ�0���ַ���ʼ���ҡ�
    string s1 = "first second third";
    string s2 = "second";
    int index = s1.find(s2, 5);//Ϊ6
    //find() �������շ��ص������ַ�����һ�γ������ַ����е���ʼ�±ꡣ�������������±�6���ҵ��� s2 �ַ�����
    //���û�в��ҵ����ַ�������ô�᷵��һ�������ֵ 4294967295��
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;

    //rfind() �� find() �����ƣ�ͬ�������ַ����в������ַ�������ͬ���� find() �����ӵڶ���������ʼ������ң�
    //�� rfind() �����������ҵ��ڶ�����������������˵ڶ���������ָ�����±껹û���ҵ����ַ������򷵻�һ�������ֵ4294967295��
    string s1 = "first second third";
    string s2 = "second";
    int index = s1.rfind(s2, 6);//Ϊ6
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;

    //find_first_of() �������ڲ������ַ������ַ�����ͬ���е��ַ����ַ������״γ��ֵ�λ�á�
    string s1 = "first second second third";
    string s2 = "asecond";
    int index = s1.find_first_of(s2);//Ϊ3
    //������ s1 �� s2 ��ͬ���е��ַ��� ��s�������ַ��� s1 ���״γ��ֵ��±���3���ʲ��ҽ������3��
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;
	return 0;
}
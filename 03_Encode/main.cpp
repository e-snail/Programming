
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

char str[100];

int main() {

    while ( cin >> str) {
        int len = strlen(str);
        cout << "input length:" <<len <<endl;
        cout << "逐字节输出:" <<endl;
        //以16进制输出，例如："汉" 的utf-8编码是 E6 B1 89
        for (int i=0; i<len; i++) {
            //cout <<hex<<str[i] <<endl;  //这样会输出乱码

            /**
             * 高位字节 (str[i] & 0xF0) >> 4
             * 低位字节 str[i] & 0x0F)
             */
            cout <<"0x" <<hex<<((str[i] & 0xF0) >> 4) <<hex<<(str[i] & 0x0F) <<endl;
        }
    }

    return 0;
}
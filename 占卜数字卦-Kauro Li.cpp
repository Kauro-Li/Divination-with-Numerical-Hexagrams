#include <iostream>
#include <cstdio>
#include <time.h>
#include <string>

using namespace std;

class 占卜数字卦
{
    void 输入值(int& a, int& b, int& c)
    {
        cout << "请输入数字：" << endl;
        if (cin >> a, b ,c && (a >= 99 && a <= 1000) && (b >= 99 && b <= 1000) && (c >= 99 && c <= 1000))
        {
            if (int(a / 10) == 0)
            {
                time_t now = time(NULL);
                tm localTimeStruct;// 使用 localtime_s 函数填充 tm 结构
                errno_t err = localtime_s(&localTimeStruct, &now);
                if (err != 0) 
                {
                    cout << "Error getting local time: " << endl;
                    _exit(0);
                }// 从 tm 结构中获取当前小时数
                int hour = localTimeStruct.tm_hour;
                switch (hour)
                {
                case 0: case 23: b = 1; break;
                case 1: case 2: b = 2; break;
                case 3: case 4: b = 3; break;
                case 5: case 6: b = 4; break;
                case 7: case 8: b = 5; break;
                case 9: case 10: b = 6; break;
                case 11: case 12: b = 7; break;
                case 13: case 14: b = 8; break;
                case 15: case 16: b = 9; break;
                case 17: case 18: b = 10; break;
                case 19: case 20: b = 11; break;
                case 21: case 22: b = 12; break;
                }
            }
            else
            {
                int bitLength = 0;
                int temp = a;
                do 
                {
                    bitLength++;
                    temp >>= 1; // 右移，直到为0
                } 
                while (temp != 0);
                int midIndex = bitLength / 2;
                int mask = (1 << midIndex) - 1; // 创建一个掩码，其中低半部分都是1
                int highHalf = a >> midIndex;          // 右移获取高半部分
                int lowHalf = a & mask;                // 与操作获取低半部分
                a = highHalf;
                b = lowHalf;
            }
            c = a + b;
        }
    }

    void 计算(int a, int b, int c, int& x, int& y, int& z)
    {
        x = a % 8;
        y = b % 8;
        z = c % 6;
    }

    void 求卦象(int x, int y, int z)
    {
        char str1[3], str2[3], str3[6];
        switch (x)
        {
        case 1: str1[0] = '1'; str1[1] = '1'; str1[2] = '1'; break;
        case 2: str1[0] = '1'; str1[1] = '1'; str1[2] = '0'; break;
        case 3: str1[0] = '1'; str1[1] = '0'; str1[2] = '1'; break;
        case 4: str1[0] = '1'; str1[1] = '0'; str1[2] = '0'; break;
        case 5: str1[0] = '0'; str1[1] = '1'; str1[2] = '1'; break;
        case 6: str1[0] = '0'; str1[1] = '1'; str1[2] = '0'; break;
        case 7: str1[0] = '0'; str1[1] = '0'; str1[2] = '0'; break;
        case 0: str1[0] = '0'; str1[1] = '0'; str1[2] = '0'; break;
        default:printf("error!"); _exit(1);
        }
        switch (y)
        {
        case 1: str2[0] = '1'; str2[1] = '1'; str2[2] = '1'; break;
        case 2: str2[0] = '1'; str2[1] = '1'; str2[2] = '0'; break;
        case 3: str2[0] = '1'; str2[1] = '0'; str2[2] = '1'; break;
        case 4: str2[0] = '1'; str2[1] = '0'; str2[2] = '0'; break;
        case 5: str2[0] = '0'; str2[1] = '1'; str2[2] = '1'; break;
        case 6: str2[0] = '0'; str2[1] = '1'; str2[2] = '0'; break;
        case 7: str2[0] = '0'; str2[1] = '0'; str2[2] = '0'; break;
        case 0: str2[0] = '0'; str2[1] = '0'; str2[2] = '0'; break;
        default:printf("error!"); _exit(1);
        }
        str3[0] = str1[0]; str3[1] = str1[1]; str3[2] = str1[2];
        str3[3] = str2[0]; str3[4] = str2[1]; str3[5] = str2[2];
        for (int I = 0; I < 2; I++)
        {
            if (I == 0)
                cout << "本卦：" << endl;
            else
            {
                if (z == 0)
                    z = 6;
                z = 6 - z;
                if (str3[z] == '0')
                    str3[z] = '1';
                else
                    str3[z] = '0';
                z++;
                cout << "变卦：" << endl;
            }
            for (int i = 0; i < 6; i++)
            {
                if (str3[i] == '1')
                    cout << "---------" << endl;
                else
                    cout << "---   ---" << endl;
            }
        }
    }

public: void Z()
    {
        cout << "作者 Kauro Li   版本v1.1.240805" << endl;
        int a, b, c, x, y, z;
        输入值(a, b, c);
        计算(a, b, c, x, y, z);
        求卦象(x, y, z);
    }
};

int main() 
{
    占卜数字卦 Z;
    Z.Z();
    return 0;
}
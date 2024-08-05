#include <iostream>
#include <cstdio>

void 输入值(int& a, int& b, int& c)
{
    printf("请输入三个三位数：\n");
    if ((scanf_s("%d,%d,%d", &a, &b, &c) != 3) || (a < 99 || a > 1000) || (b < 99 || b > 1000) || (c < 99 || c > 1000))
    {
        printf("输入错误！\n");
        _exit(1);
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
            printf("本卦：\n");
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
            printf("变卦：\n");
        }
        for (int i = 0; i < 6; i++)
        {
            if (str3[i] == '1')
                printf("---------\n");
            else
                printf("---   ---\n");
        }
    }
}

void 占卜数字卦()
{
    printf("作者 Kauro Li   版本1.1.240805\n");
    int a, b, c, x, y, z;
    输入值(a, b, c);
    计算(a, b, c, x, y, z);
    求卦象(x, y, z);
}
int main() 
{
    占卜数字卦();
    return 0;
}
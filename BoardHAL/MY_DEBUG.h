#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#include "CLLC_HAL.h"

void CLLC_HAL_DEBUG_Transnit(void);

// 将整数转换为字符串并返回长度
static inline int intToStr(int num, char *str)
{
    int i = 0;
    int isNegative = 0;
    // 处理负数
    if (num < 0)
    {
        isNegative = 1;
        num = -num;
    }
    // 将数字转换为字符串，逆序存储
    do
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative)
    {
        str[i++] = '-';
    }
    // 反转字符串
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    // 返回生成的字符串长度
    str[i] = '\0';
    return i;
}

// 将浮点数格式化为字符串
static inline void formatData(float Vprim, float Vsec, float Iprim1, float Isec1, char *DEBUG_Buffer)
{
    int32_t Vprim_int = (int)(Vprim);
    int32_t Vsec_int = (int)(Vsec);
    int32_t Iprim1_int = (int)(Iprim1);
    int32_t Isec1_int = (int)(Isec1);

    // 临时缓冲区用于存储每个整数的字符串表示
    // char temp[12]; // 足够存储整数和符号
    int len = 0;
    // 将 Vprim_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Vprim_int, DEBUG_Buffer + len);
    // 添加逗号
    DEBUG_Buffer[len++] = ',';
    // 将 Vsec_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Vsec_int, DEBUG_Buffer + len);
    // 添加逗号
    DEBUG_Buffer[len++] = ',';
    // 将 Iprim1_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Iprim1_int, DEBUG_Buffer + len);
    // 添加逗号
    DEBUG_Buffer[len++] = ',';
    // 将 Isec1_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Isec1_int, DEBUG_Buffer + len);
    // 添加换行符
    DEBUG_Buffer[len++] = '\n';
    // 添加字符串结束符
    DEBUG_Buffer[len] = '\0';
}

static inline void UARTprintf(const char *pcString)
{
    while (*pcString != '\0')
    {
        SCI_writeCharBlockingFIFO(DEBUG_BASE, *pcString++);
    }
}

#endif // DEBUG_H

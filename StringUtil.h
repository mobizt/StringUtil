#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <Arduino.h>

class StringUtil {
  private:
    char outBuf[80];
    void crlf();

  public:
    char inBuf1[80];
    char inBuf2[80];
    uint16_t strpos(const char *haystack, const char *needle, int offset);
    char* midString(const char *str, int start, int len);
    char* addString(const char *str1, const char *str2);
    char* leftString(const char *str, int len);
    long toLong(const char *str);
    int toInt(const char *str);
    float toFloat(const char *str);
    uint8_t toAscii(const char *str);
    char* toChar(uint8_t c);
    int strlen(const char *str);
    char* longToHexString(long n);
    char* longToBinaryString(long n);
    char* longToString(long n);
    char* integerToString(int n);
    int stringCompare(const char *str1, const char *str2);
    void printString(const char *str);
    char* getString(const char* str);

};

#endif


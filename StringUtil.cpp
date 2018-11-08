#include "StringUtil.h"


uint16_t StringUtil::strpos(const char *haystack, const char *needle, int offset)
{
  char _haystack[strlen(haystack)];
  strncpy(_haystack, haystack + offset, strlen(haystack) - offset);
  char *p = strstr(_haystack, needle); // get string pointer
  if (p)
    return p - _haystack + offset + 1;
  return -1;
}

char* StringUtil::midString(const char *str, int start, int len)
{
  strncpy(outBuf, (char*)str + start - 1, len); // copy to outputString using Basic nomenclature where 1 is the first character
  outBuf[len] = '\0'; // put in new null terminator
  return outBuf;
}

char* StringUtil::addString(const char *str1, const char *str2)
{
  strcat((char*) str1, (char*) str2);
  strcpy(outBuf, str1);
  return outBuf;
}

char* StringUtil::leftString(const char *str, int len)
{
  strncpy(outBuf, (char*)str, len);
  outBuf[len] = '\0';
  return outBuf;
}

long StringUtil::toLong(const char *str) {
  return atol(str);
}
int StringUtil::toInt(const char *str){
  return atoi(str);
}
float StringUtil::toFloat(const char *str){
  return atof(str);
}

uint8_t StringUtil::toAscii(const char *str) // returns ascii value of the left most character in a string.
{
  uint8_t c = str[0];
  return c;
}

char* StringUtil::toChar(uint8_t c) // convert c to a string of length 1 character
{
  outBuf[0] = c;
  outBuf[1] = '\0'; // null terminator
  return outBuf;
}

int StringUtil::strlen(const char *str)
{
  return strlen(str);
}

char* StringUtil::longToHexString(long n)
{
  ltoa(n, outBuf, 16); // base 16 is binary, returns lower case A-F
  return outBuf;
}

char* StringUtil::longToBinaryString(long n)
{
  ltoa(n, outBuf, 2); // base 2 is binary
  return outBuf;
}

char* StringUtil::longToString(long n)
{
  ltoa(n, outBuf, 10); // base 10
  return outBuf;
}

char* StringUtil::integerToString(int n) // returns outputString
{
  itoa(n, outBuf, 10); // itoa is for integers, 10 is for base 10 (could use 2 for binary, 16 for hex)
  return outBuf;
}

int StringUtil::stringCompare(const char *str1, const char *str2)
{
  uint8_t a = strcmp(str1, str2); // 0 is a match
  return a;
}

void StringUtil::printString(const char *str) // all output directed through this one routine, so can change Serial.print to whatever display is being used
{
  const char *p;
  p = str;
  while (*p) {
    Serial.print(*p); // explanation in majenko's webpage
    p++;
  }
}

void StringUtil::printStringln(const char *str) // print line with crlf
{
  printString(str);
  crlf(); // carriage return, line feed
}

void StringUtil::crlf() // carriage return and linefeed
{
  const static char crlf[] PROGMEM = "\r\n"; // carriage return, then line feed, maybe not the most efficient way to do this but works
  printString(getString(crlf)); // print out, using one central function for output so easier to change destination with different displays
}

char* StringUtil::getString(const char* str) // String replacement - move string from flash to local buffer
{
  strcpy_P(outBuf, (char*)str);
  return outBuf;
}


#include <iostream>
using namespace std;




char* CopyString(const char* str)
{
    int size=0;
    
    for (int i=0;str[i]!='\0';i++)
    {
        size++;
    }
    
    
    char* newstr=new char[size];
    memcpy(newstr,str,size);
    return newstr;
}




char* ConcatinateStrings(const char* a, const char* b)
{
    int sa=0;
    int sb=0;
    
    for (int i=0; a[i]!='\0';i++)
    {
        sa++;
    }
    
    
    for (int i=0; b[i]!='\0';i++)
    {
        sb++;
    }
    
    
    char* newstr = new char[sa + sb];
    memcpy(newStr, a, sa);
    memcpy(newStr + sa, b, sb);
    return newStr;
}
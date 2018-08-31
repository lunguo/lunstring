/*************************************************************************
	> File Name: lunstring.h
	> Author: 
	> Mail: 
	> Created Time: Fri 31 Aug 2018 09:26:02 AM CST
 ************************************************************************/

#ifndef _LUNSTRING_H
#define _LUNSTRING_H
#include<iostream>
using namespace std;
class lunstring
{
private:
    char* buff;
public:
    lunstring();
    lunstring(const char* str);
    lunstring(const lunstring& ls);
    lunstring operator+(const lunstring& ls);
    lunstring&  operator=(const lunstring& ls);

    char operator[](int index);
    bool operator==(const lunstring& ls);
    bool operator!=(const lunstring& ls);
    bool operator>(const lunstring& ls);
    bool operator<(const lunstring& ls);

    int to_int() const;
    float to_float() const;

    operator int();
    operator float();

    friend istream& operator>>(istream& in, lunstring& ls);
    friend ostream& operator<<(ostream& out,const lunstring& ls);

    int size() const;
    bool empty() const;
    void clear();
    void append(const char* str);
    void insert(int index,const char* str);
    void remove(const char* str);
    void replace(const char* oldstr,const char* newstr);
    const char* c_str() const;

    ~lunstring();
};


#endif

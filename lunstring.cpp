/*************************************************************************
	> File Name: lunstring.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 31 Aug 2018 09:35:17 AM CST
 ************************************************************************/

#include"lunstring.h"
#include<cstring>

lunstring::lunstring()
{
    buff=new char[2];
    buff[0]='\0';
//    buff=NULL;
}

lunstring::lunstring(const char* str)
{
    buff=new char[strlen(str)+1];
    strcpy(buff,str);
}
lunstring::lunstring(const lunstring& ls)
{
    buff=new char[strlen(ls.buff)+1];
    strcpy(buff,ls.buff);
}
lunstring lunstring::operator+(const lunstring& ls)
{
    lunstring tmp;
    delete [](tmp.buff);
    tmp.buff=new char[strlen(buff)+strlen(ls.buff)+2];
    strcpy(tmp.buff,this->buff);
  strcat(tmp.buff,ls.buff);

    return tmp;
}
lunstring& lunstring::operator=(const lunstring& ls)
{
    delete []buff;
    buff=new char[strlen(ls.buff)+1];
    strcpy(buff,ls.buff);
}
int lunstring::size() const
{
    return strlen(buff);
}
bool lunstring::empty() const
{
    return (buff[0]=='\0');
}
void lunstring::clear()
{
    buff[0]='\0';
}
istream& operator>>(istream& in, lunstring& ls)
{
    char* input_buff=NULL;
    int size=1000;
    int cnt=0;
    char chr;

    input_buff=new char[size+1];

    while(1)
    {
        chr=in.get();
        if('\n'==chr) break;
        input_buff[cnt++]=chr;

        if(size==cnt)
        {
            size+=100;
            char* temp_buff=new char[size+1];
            memcpy(temp_buff,input_buff,cnt);
            delete []input_buff;
            input_buff=temp_buff;
        }
    }
    input_buff[cnt]='\0';
    ls.buff=new char[strlen(input_buff)+1];
    strcpy(ls.buff,input_buff);
   // delete []ls.buff;

    return in;

}
lunstring::~lunstring()
{
    delete []buff;
}

//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.

#include "cstring.h"
namespace sdds 
{
    void strCpy(char *des, const char *src)
    {
        while (*src) 
        {
            *des = *src;
            src++;
            des++;
        }
        *des = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int length=0;
        int i = 0;
        while (src[i] != '\0')
        {
            length++;
            i++;
        }



        if (len <= length)
        {
            while (*src!='\0' && len!=0)


            {
                *des = *src;
                des++;
                src++;
                len--;
            }
        }

        else
        {
            while (*src!='\0' && len!=0)
            {
                *des = *src;
                des++;
                src++;
            }
            *des = '\0';
        }

    }
    int strCmp(const char *s1, const char *s2) 
    {
        while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
        {
            s1++;
            s2++;
        }
        if (*s1 == *s2)
        {
            return 0;
        } else 
        {
            return *s1 - *s2;
        }
    }
    int strnCmp(const char* s1, const char* s2, int len)
    {
        int posn = 0, flag = 0;
        while (s1[posn] != '\0' && s2[posn] != '\0' && posn < len)
        {
            if (s1[posn] == s2[posn])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            posn++;
        }
        if (flag == 1) 
        {
            return 0;
        }
        else
        {
            return 1; 
        }

    }
    int strLen(const char *s) 
    {
        int count = 0;
        while (*s != '\0')
        {
            s++;
            count++;
        }
        return count;
    }


    const char* strStr(const char* str1, const char* str2)
    {

        int length = 0; 
        const char* temp = str2;
        while(*temp!='\0')
        {
            length++;
            temp++;
        }

        int flag;
        while (*str1!='\0')
        {
            flag = 1;
            int i = 0;
            for (i = 0; i < length; i++)
            {
                if (str1[i] != str2[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                return str1;
            }
            str1++;
        }
        return nullptr;
    }
    void strCat(char *des, const char *src) 
    {
        while (*des != '\0') 
        {
            des++;
        }
        while (*src != '\0') 
        {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }
}
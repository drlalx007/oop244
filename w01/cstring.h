//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :30/05/2021.

#ifndef DIY_CSTRING_H
#define DIY_CSTRING_H
namespace sdds {

    void strCpy(char *des, const char *src);
    void strnCpy(char *des, const char *src, int len);
    int strCmp(const char *s1, const char *s2);
    int strnCmp(const char *s1, const char *s2, int len);
    int strLen(const char *s);
    const char *strStr(const char *str1, const char *str2);
    void strCat(char *des, const char *src);
}
#endif //DIY_CSTRING_H

//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :08/07/2021.

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
    class Text;
    class Line {

        char* val{ nullptr };
        operator const char* ()const;
        Line() {};
        Line& operator=(const char*);
        ~Line();
        friend class TextFile;
    };

    class TextFile {
        Line* txtlines{ nullptr };
        char* file_name{ nullptr };
        unsigned no_of_lines;
        unsigned p_size;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();

    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__
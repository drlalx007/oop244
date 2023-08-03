//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :08/07/2021.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    Line::operator const char* () const {
        return (const char*)val;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] val;
        val = new char[strLen(lineValue) + 1];
        strCpy(val, lineValue);
        return *this;
    }

    Line::~Line() {
        if (val) {
            delete[] val;
        }
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {

        if (isCopy) {

            file_name = new char[strLen(fname) + 3];
            strCpy(file_name, "C_");
            strCat(file_name, fname);
        }
        else {

            file_name = new char[strLen(fname) + 1];
            strCpy(file_name, fname);
        }
    }

    void TextFile::setNoOfLines() {
        char newLine;
        ifstream fileRead(file_name);
        if (fileRead.is_open()) {
            while (fileRead) {
                newLine = fileRead.get();
                if (newLine == '\n')
                    no_of_lines++;
            }
            no_of_lines++;
        }
        else {
            delete[] file_name;
            file_name = nullptr;
        }

        if (no_of_lines == 0) {
            delete[] file_name;
            file_name = nullptr;
        }
    }

    void TextFile::loadText() {

        if (file_name) {

            // Variables:
            unsigned count = 0;
            string textLine;

            if (txtlines) {
                delete[] txtlines;
                txtlines = nullptr;

            }
            txtlines = new Line[no_of_lines];

            ifstream fileRead(file_name);

            if (fileRead.is_open()) {
                while (getline(fileRead, textLine)) {
                    txtlines[count].val = new char[strLen(textLine.c_str()) + 1];
                    strCpy(txtlines[count].val, textLine.c_str());
                    count++;
                }
            }
            no_of_lines = count;
        }
    }

    void TextFile::saveAs(const char* fileName)const {

        ofstream fout(fileName);

        if (fout.is_open()) {
            for (unsigned i = 0; i < no_of_lines; i++) {
                fout << txtlines[i] << endl;
            }
        }
    }

    void TextFile::setEmpty() {

        if (txtlines) {
            delete[] txtlines;
            txtlines = nullptr;
        }

        if (file_name) {
            delete[] file_name;
            file_name = nullptr;
        }
        no_of_lines = 0;
    }

    TextFile::TextFile(unsigned pageSize) {

        setEmpty();
        p_size = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {

        setEmpty();
        p_size = pageSize;

        if (filename && filename[0] != '\0') {

            file_name = new char[strLen(filename) + 1];
            strCpy(file_name, filename);

            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& src) {
        setEmpty();
        p_size = src.p_size;

        if (src.file_name && src.no_of_lines > 0) {
            setFilename(src.file_name, true);

            txtlines = new Line[src.no_of_lines];

            for (unsigned i = 0; i < src.no_of_lines; i++) {
                txtlines[i].val = new char[strLen(src.txtlines[i].val) + 1];
                strCpy(txtlines[i].val, src.txtlines[i].val);
            }
            no_of_lines = src.no_of_lines;
            saveAs(file_name);
        }
    }
    TextFile& TextFile::operator=(const TextFile& src) {

        if (this != &src) {

            delete[] txtlines;
            txtlines = nullptr;

            if (src.txtlines) {

                no_of_lines = src.no_of_lines;
                txtlines = new Line[no_of_lines];
                unsigned i = 0;
                while (i < no_of_lines) {
                    txtlines[i].val = new char[strLen(src.txtlines[i].val) + 1];
                    strCpy(txtlines[i].val, src.txtlines[i].val);
                    i++;
                }
                saveAs(file_name);
            }
        }
        return *this;
    }
    TextFile::~TextFile() {

        delete[] file_name;
        file_name = nullptr;

        delete[] txtlines;
        txtlines = nullptr;
    }
    unsigned TextFile::lines()const {

        return no_of_lines;
    }
    std::ostream& TextFile::view(std::ostream& ostr)const {

        if (file_name && file_name[0] != '\0') {

            unsigned file_Line = 0;
            char c;

            ostr << file_name << endl;
            for (int fileLine = 0; fileLine < strLen(file_name); fileLine++) {
                ostr << '=';
            }
            ostr << endl;

            for (file_Line = 0; file_Line < no_of_lines && file_Line < p_size; file_Line++) {
                ostr << txtlines[file_Line] << endl;
            }

            if (file_Line < no_of_lines) {
                do {
                    ostr << "Hit ENTER to continue...";
                    cin.get(c);

                    for (unsigned j = 0; j < p_size && file_Line < no_of_lines; j++) {
                        ostr << txtlines[file_Line] << endl;
                        file_Line++;
                    }
                } while (file_Line < no_of_lines);
            }
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string m_fileName;
        istr >> m_fileName;
        file_name = new char[strLen(m_fileName.c_str()) + 1];
        strCpy(file_name, m_fileName.c_str());
        istr.ignore(30000, '\n');
        setNoOfLines();
        loadText();
        return istr;
    }
    const char* TextFile::operator[](unsigned index)const {
        if (file_name && file_name[0] != '\0') {

            if (index >= no_of_lines)
                index -= no_of_lines;
        }
        return (txtlines[index].val);
    }
    TextFile::operator bool()const {
        return (txtlines);
    }
    const char* TextFile::name()const {
        return file_name;
    }
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }
}
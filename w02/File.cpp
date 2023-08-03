//    Name     :Daryl Alex
//    ID       :143691202
//    Email    :dalex4@myseneca.ca
//    Section  :ZBB
//    Date     :06/06/2021.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
namespace sdds
{
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char name[])
    {
	    return fscanf(fptr, "%[^,],", name) == 1;
    }

    bool read(int& population_count)
    {
        return fscanf(fptr, "%d\n", &population_count) == 1;
    }

}
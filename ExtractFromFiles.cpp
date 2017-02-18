//
// Created by akshit on 18/2/17.
//

#include <dirent.h>
#include <vector>
#include <fstream>
#include "ExtractFromFiles.h"
#include "GlobalHeader.h"
#include "AttributesHolder.h"


ExtractFromFiles::ExtractFromFiles(std::string folderPath) {
    this->folderpath = std::string(folderPath);
}

int ExtractFromFiles::extractListOfFiles(std::vector<std::string> * files) {
    DIR *dp;
    struct dirent *dirp;

    if((dp = opendir(folderpath.c_str())) == NULL){
        printf_stream(stderr, "Error (%d) opening %s", errno, folderpath.c_str());
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL){
        if((dirp->d_name[0])=='.')
            continue;
        std::string file_name = std::string(folderpath + PATH_SEPARATOR + dirp->d_name);
        (*files).push_back(file_name);
    }

    closedir(dp);
    return 0;
}

void ExtractFromFiles::extractAttriFromFiles(std::string file_name, FILE * file_output,
                                             int ham_status){
    FILE * file;
    fopen_stream(&file,file_name.c_str(),"r");

    AttributesHolder attributesHolder;
    attributesHolder.extractAttributes(file, ham_status);
    attributesHolder.writeAttributes(file_output);

    fclose(file);

}


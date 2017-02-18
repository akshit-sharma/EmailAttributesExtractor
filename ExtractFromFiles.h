//
// Created by akshit on 18/2/17.
//

#ifndef EXTRACTEMAILATTRIBUTES_EXTRACTFROMFILES_H
#define EXTRACTEMAILATTRIBUTES_EXTRACTFROMFILES_H

#include <string>

class ExtractFromFiles {
    std::string folderpath;

public:
    ExtractFromFiles(std::string folderPath);
    int extractListOfFiles(std::vector<std::string> * files);
    void extractAttriFromFiles(std::string file_name, FILE * file_output,
                               int ham_status);

};


#endif //EXTRACTEMAILATTRIBUTES_EXTRACTFROMFILES_H

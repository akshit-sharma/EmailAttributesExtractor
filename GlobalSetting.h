//
// Created by akshit on 18/2/17.
//

#ifndef EXTRACTEMAILATTRIBUTES_GLOBALSETTING_H
#define EXTRACTEMAILATTRIBUTES_GLOBALSETTING_H

#include <string>

class GlobalSetting {
private:
    std::string workingDir;
    std::string outputFile;
    std::string trainingDataDir;

    static GlobalSetting* instance;

public:

    static GlobalSetting* get();

    void setWorkingDir(char *location);
    void setWorkingDir(std::string location);
    std::string getWorkingDir();
    const char * getWorkingDirC();

    std::string getTrainingDir();

    void setOutputFile(std::string file_location);
    std::string getOutputFile();

};


#endif //EXTRACTEMAILATTRIBUTES_GLOBALSETTING_H

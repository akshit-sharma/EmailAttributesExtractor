//
// Created by akshit on 18/2/17.
//
#include "GlobalSetting.h"

GlobalSetting* GlobalSetting::instance = NULL;

GlobalSetting* GlobalSetting::get(){

    if(!instance)
        instance = new GlobalSetting;

    return GlobalSetting::instance;

}

void GlobalSetting::setWorkingDir(char *location){
    workingDir = std::string(location);
    trainingDataDir = workingDir + "/TRAINING";
}

void GlobalSetting::setWorkingDir(std::string location){
    workingDir = std::string(location);
    trainingDataDir = workingDir + "/TRAINING";
}

std::string GlobalSetting::getWorkingDir(){
    return workingDir;
}

const char * GlobalSetting::getWorkingDirC(){
    return workingDir.c_str();
}

void GlobalSetting::setOutputFile(std::string file_location) {
    outputFile = std::string(file_location);
}

std::string GlobalSetting::getOutputFile() {
    return outputFile;
}

std::string GlobalSetting::getTrainingDir() {
    return trainingDataDir.c_str();
}
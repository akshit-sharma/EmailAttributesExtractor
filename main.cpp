#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "GlobalHeader.h"
#include "GlobalSetting.h"
#include "ExtractFromFiles.h"

int main(int argc, char ** argv) {

    if(argc!=3){
        printf_stream(stderr,"Arguments Error\n");
        printf_stream(stderr,"Usage ExtractEmailAttributes InputFolder OutputCSVFile\n");
    }else{
        GlobalSetting::get()->setWorkingDir(argv[1]);
        GlobalSetting::get()->setOutputFile(argv[2]);
    }

    ExtractFromFiles eff (GlobalSetting::get()->getTrainingDir());
    std::vector<std::string> list_of_files;
    eff.extractListOfFiles(&list_of_files);

    FILE * output_file;
    FILE * answer_file;
    std::vector<std::string>::iterator iter_files;
    char file_name_faaltu[256];

    printf_stream(stdout,"Output file : %s \n", GlobalSetting::get()->getOutputFile().c_str());
    fopen_stream(&output_file,(GlobalSetting::get()->getOutputFile().c_str()),"w");
    fopen_stream(&answer_file,(GlobalSetting::get()->getWorkingDir()+"/SPAMTrain.label").c_str(),"r");

    std::sort(list_of_files.begin(), list_of_files.end());

    for(iter_files = list_of_files.begin();
            iter_files != list_of_files.end(); ++iter_files){
        printf_stream(stdout, "Extracting %s \n", (*iter_files).c_str());
        int ham_label;
        scanf_stream(answer_file,"%d %s",&ham_label, &file_name_faaltu[0]);
        eff.extractAttriFromFiles(*iter_files, output_file, ham_label);
    }

    fclose(output_file);
    fclose(answer_file);


    return 0;
}
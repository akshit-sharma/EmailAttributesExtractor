//
// Created by akshit on 18/2/17.
//

#ifndef EXTRACTEMAILATTRIBUTES_ATTRIBUTESHOLDER_H
#define EXTRACTEMAILATTRIBUTES_ATTRIBUTESHOLDER_H

#include <string>
#include <fstream>

const int ALPHA_CHARS = 36;
const int SPECIAL_CHARS = 10;
const int PUNCT_CHARS = 14;

// using http://stackoverflow.com/questions/770238/neural-networks-for-email-spam-detection
// for attributes selection

class AttributesHolder {
    std::string file_name;

    uint64_t total_chars;
    uint64_t normal_chars;
    uint64_t digit_chars;
    uint64_t whitespace;
    uint64_t freq_alpha[ALPHA_CHARS];
    uint64_t freq_special[SPECIAL_CHARS];
    uint64_t freq_punct[PUNCT_CHARS];
    uint64_t total_words;
    uint64_t total_short_words; // 2 letters or less
    uint64_t total_chars_in_words; // chars in bigger words
    uint64_t total_word_length;
    uint64_t total_sentence_chars;
    uint64_t total_sentence_words;
    uint64_t total_sentence;
    int ham_status;

public:
    AttributesHolder();
    void extractAttributes(FILE * input_stream, int input_labels);
    void writeAttributes(FILE * output_stream);

};


#endif //EXTRACTEMAILATTRIBUTES_ATTRIBUTESHOLDER_H

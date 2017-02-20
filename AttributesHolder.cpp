//
// Created by akshit on 18/2/17.
//
#include <cinttypes>
#include "GlobalHeader.h"
#include "AttributesHolder.h"

AttributesHolder::AttributesHolder() {
    total_chars = 0;
    normal_chars = 0;
    digit_chars = 0;
    whitespace = 0;
    total_words = 0;
    total_short_words = 0; // 2 letters or less
    total_chars_in_words = 0; // chars in bigger words
    total_word_length = 0;
    total_sentence_chars = 0;
    total_sentence_words = 0;
    total_sentence = 0;

    for(size_t i=0; i<ALPHA_CHARS; i++)
        freq_alpha[i] = 0;
    for(size_t i=0; i<SPECIAL_CHARS; i++)
        freq_special[i] = 0;
    for(size_t i=0; i<PUNCT_CHARS; i++)
        freq_punct[i] = 0;

}

void AttributesHolder::extractAttributes(FILE * input_stream, int input_labels){

    char character;
    bool diffWord;
    int special_index;
    int punct_index;
    int word_char_count;

    ham_status = input_labels;

    diffWord = true;
    word_char_count = 0;
    total_short_words = 0;
    total_chars_in_words = 0;
    total_sentence_chars = 0;
    total_sentence_words = 0;
    total_sentence = 0;

    while ( (scanf_stream(input_stream,"%c",&character)) != EOF){
        total_chars++;
        if((character>='A'&&character<='Z')||
                (character>='a'&&character<='z')){
            normal_chars++;
            if(character>='A'&&character<='Z'){
                freq_alpha[character-'A']++;
            }
            if (character>='a'&&character<='z'){
                freq_alpha[character-'a']++;
            }
            if(!diffWord) {
                word_char_count++;
                total_chars_in_words++;
            }
            if(diffWord)
                diffWord = false;
            total_sentence_chars++;
        }
        if(character >= 0 && character <= 9){
            digit_chars++;
            if(character>=0 && character<=9){
                freq_alpha[character+27]++;
            }
            if(!diffWord) {
                word_char_count++;
                total_chars_in_words++;
            }
            if(diffWord)
                diffWord = false;
            total_sentence_chars++;
        }
        if(character == ' '){
            whitespace++;
            if(!diffWord){
                diffWord = true;
                total_words++;
                if(word_char_count<=2)
                    total_short_words++;
                total_word_length += word_char_count;
                total_sentence_words++;
                word_char_count = 0;
            }
        }
        if(character == '.'){
            total_sentence++;
        }

        special_index = 0;
        punct_index = 0;
        switch (character){
            case '*':
                special_index++;
            case '_':
                special_index++;
            case '+':
                special_index++;
            case '=':
                special_index++;
            case '%':
                special_index++;
            case '$':
                special_index++;
            case '@':
                special_index++;
            case '\\':
                special_index++;
            case '/':
                freq_special[special_index]++;
                break;
            case '.':
                punct_index++;
            case ',':
                punct_index++;
            case ';':
                punct_index++;
            case '?':
                punct_index++;
            case '!':
                punct_index++;
            case ':':
                punct_index++;
            case '(':
                punct_index++;
            case ')':
                punct_index++;
            case '-':
                punct_index++;
            case '"':
                punct_index++;
            case '<':
                punct_index++;
            case '>':
                punct_index++;
            case '[':
                punct_index++;
            case ']':
                freq_punct[punct_index]++;
                break;
            default:
                break;
        }

    }
    total_sentence++;

}

void AttributesHolder::writeAttributes(FILE * output_stream) {
    printf_stream(output_stream, "%" PRIu64 ",%f,%f,%f,", total_chars,
                  ((float)(normal_chars+digit_chars)/total_chars),
                  ((float)(digit_chars)/total_chars),
                  ((float) whitespace/total_chars));
    for(size_t i=0; i<ALPHA_CHARS; i++)
        printf_stream(output_stream,"%f,",(float)freq_alpha[i]/total_chars);
    for(size_t i=0; i<SPECIAL_CHARS; i++)
        printf_stream(output_stream,"%f,",(float)freq_special[i]/total_chars);
    for(size_t i=0; i<PUNCT_CHARS; i++)
        printf_stream(output_stream,"%f,",(float)freq_punct[i]/total_chars);
    printf_stream(output_stream, "%" PRIu64 ",%f,%f,%f,%f,%f,", total_words,
                  ((float) total_short_words/total_words),
                  ((float) total_chars_in_words/total_chars),
                  ((float) total_word_length/total_words),
                  ((float) total_sentence_chars / total_sentence),
                  ((float) total_sentence_words / total_sentence));
    std::string status = std::string("spam");
    if(ham_status==1){
        status = std::string("ham");
    }
    printf_stream(output_stream, "'%s'\n",
                  status.c_str()    );
    fflush(output_stream);

}


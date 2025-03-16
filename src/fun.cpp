// Copyright 2022 UNN-IASR
#include <cctype>
#include <cmath>
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool in_word = false;
    bool has_numbers = false;
    int count = 0;
    while (*str) {
        if (in_word == false && *str != ' ') {
            in_word = true;
        } else if (in_word == true && *str ==' ') {
            if (has_numbers == false) count++;
            in_word = false;
            has_numbers = false;
        }

        if (in_word ==true) {
            if ( '0' <= *str && *str <= '9') {
                has_numbers = true;
            }
        }
        *str++;
    }
    return count;

}

unsigned int faStr2(const char *str) {
    bool in_word = false;
    bool is_bigger = false;
    bool is_correct = true;
    int count = 0;
    while (*str) {
        if (in_word == false && *str != ' ') {
            in_word = true;
            if (std::isupper(*str)) {
                is_bigger = true;
            }
        }
        else if (in_word == true && *str ==' ') {
            if (is_correct == true && is_bigger == true) count++;
            in_word = false;
            is_correct = true;
            is_bigger = false;
        }

        if (in_word ==true){
            if (is_bigger == true) {
                if (!('a' <= *str && *str <= 'z')) {
                    is_correct = false;
                }
            }
            
        }
        *str++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    bool in_word = false;
    bool has_numbers = false;
    int length = 0;
    int count = 0;
    while (*str) {
        if (in_word == false && *str != ' ') {
            in_word = true;
            count++;
        }
        else if (in_word == true && *str == ' ') {
            if (has_numbers == false) count++;
            in_word = false;
            has_numbers = false;
        }

        if (in_word ==true) {
             length++;
        }

        *str++;
    }
    return std::round(length/count);
}

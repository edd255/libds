#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "str.h"

size_t char_get_length(const char *str)
{
    const char* s;
    for (s = str; *s; ++s);
    return s - str;
}


str_t* string_init(char* data)
{
        str_t* string = (str_t*) malloc(sizeof(str_t));
        string -> length = char_get_length(data);
        string -> data = data;
        return string;
}

void string_free(str_t* self)
{
        free(self);
}

str_t* string_prepend(str_t* self, str_t* to_prepend)
{
        return string_append(to_prepend, self);
}

str_t* string_append(str_t* self, str_t* to_append)
{
        str_t* string = (str_t*) malloc(sizeof(str_t));
        size_t new_length = self -> length + to_append -> length;
        string -> data = (char*) malloc(new_length * sizeof(char));
        for (int i = 0; i < self -> length; i++) {
                string -> data[i] = self -> data[i];
        }
        for (int i = 0; i < to_append -> length; i++) {
                string -> data[self -> length + i] = to_append -> data[i];
        }
        return string;
}

bool string_equals(str_t* self, str_t* other)
{
        if (self -> length != other -> length) {
                return false;
        }
        for (int i = 0; i < self -> length; i++) {
                if (self -> data[i] != other -> data[i]) {
                        return false;
                }
        }
        return true;
}

bool string_is_substring_of(str_t* self, str_t* other)
{
        if (self -> length < other -> length) {
                return false;
        }
        for (int i = 0; i < self -> length; i++) {
                if (self -> data[i] == other -> data[0]) {
                        int start = i;
                        int end = start + other -> length;
                        if (end > self -> length) {
                                return false;
                        }
                        for (int j = start; j < end; j++) {
                                if (self -> data[j] != other -> data[j]) {
                                        return false;
                                }
                        }
                        return true;
                }
        }
        return false;
}

int string_index_of(str_t* self, char* character)
{
        if (self -> length == 0) {
                return -1;
        }
        for (int i = 0; i < self -> length; i++) {
                if (self -> data[i] == character[0]) {
                        return i;
                }
        }
        return -1;
}

void string_fill(str_t* self, char* character)
{
        for (int i = 0; i < self -> length; i++) {
                self -> data[i] = character[0];
        }
}

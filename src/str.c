#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "ds.h"

static size_t char_get_length(const char *str)
{
    const char* s;
    for (s = str; *s; ++s);
    return s - str;
}


static str_t* string_init(char* data)
{
        str_t* string = (str_t*) malloc(sizeof(str_t));
        string -> length = char_get_length(data);
        string -> data = data;
        return string;
}

static void string_free(str_t* self)
{
        free(self);
}

static str_t* string_append(str_t* self, str_t* to_append)
{
        str_t* str = (str_t*) malloc(sizeof(str_t));
        size_t new_length = self -> length + to_append -> length;
        str -> data = (char*) malloc(new_length * sizeof(char));
        for (int i = 0; i < self -> length; i++) {
                str -> data[i] = self -> data[i];
        }
        for (int i = 0; i < to_append -> length; i++) {
                str -> data[self -> length + i] = to_append -> data[i];
        }
        return str;
}

static str_t* string_prepend(str_t* self, str_t* to_prepend)
{
        return string_append(to_prepend, self);
}

static bool string_equals(str_t* self, str_t* other)
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

static bool string_is_substring_of(str_t* self, str_t* other)
{
        if (self -> length < other -> length) {
                return false;
        }
        for (int i = 0; i < self -> length; i++) {
                if (self -> data[i] != other -> data[0]) {
                        continue;
                }
                int start = i;
                int end = i + other -> length;
                for (int j = start; j < end; j++) {
                        if (self -> data[j] != other -> data[j - i]) {
                                continue;
                        }
                }
                return true;
        }

        return false;
}

static int string_index_of(str_t* self, char* character)
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

static void string_fill(str_t* self, char* character)
{
        for (int i = 0; i < self -> length; i++) {
                self -> data[i] = character[0];
        }
}

namespace_string const string = {
        string_init,
        string_free,
        string_prepend,
        string_append,
        string_equals,
        string_is_substring_of,
        string_index_of,
        string_fill
};

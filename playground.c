#include <stdbool.h>
#include <stdio.h>
#include "src/str.h"

int main()
{
        str_t* string1 = string_init("edd255");
        str_t* string2 = string_init("edd255");
        printf("%s\n", string1 -> data);
        if (string1 -> length == 6) {
                printf("Has length 6.\n");
        }
        if (string_equals(string1, string2)) {
                printf("Strings are equal.\n");
        }
        if (string_is_substring_of(string1, string2)) {
                printf("Are substrings.\n");
        }
        int idx = string_index_of(string1, "d");
        printf("Index of d: %d\n", idx);
        string_fill(string1, "c");
        printf("New string: %s\n", string1 -> data);
        string_free(string1);
        string_free(string2);
        return 0;
}

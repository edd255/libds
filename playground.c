#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "src/str.h"


void test_length_1()
{
        str_t* string = string_init("edd255");
        assert(string -> length == 6);
        string_free(string);
}

void test_equality_1()
{
        str_t* string1 = string_init("edd255");
        str_t* string2 = string_init("edd255");
        assert(string_equals(string1, string2));
        string_free(string1);
        string_free(string2);
}

void test_substring_1()
{
        str_t* string = string_init("edd255");
        str_t* sub = string_init("d2");
        assert(string_is_substring_of(string, sub));
        string_free(string);
        string_free(sub);
}

void test_index_of_1()
{
        str_t* string = string_init("edd255");
        assert(string_index_of(string, "d") == 1);
        string_free(string);
}

void test_append()
{
        str_t* string1 = string_init("Hello ");
        str_t* string2 = string_init("World!");
        str_t* string3 = string_append(string1, string2);
        str_t* string4 = string_init("Hello World!");
        assert(string3 -> data == string3 -> data);
        string_free(string1);
        string_free(string2);
        string_free(string3);
        string_free(string4);
}


int main()
{
        test_length_1();
        test_equality_1();
        test_substring_1();
        test_index_of_1();
        test_append();
        return 0;
}

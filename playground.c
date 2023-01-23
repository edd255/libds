#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "src/str.h"


void test_length_1()
{
        str_t* str = string.init("edd255");
        assert(str -> length == 6);
        string.free(str);
}

void test_length_2()
{
        str_t* str = string.init("");
        assert(str -> length == 0);
        string.free(str);
}

void test_equality_1()
{
        str_t* string1 = string.init("edd255");
        str_t* string2 = string.init("edd255");
        assert(string.equals(string1, string2));
        string.free(string1);
        string.free(string2);
}

void test_equality_2()
{
        str_t* string1 = string.init("edd255");
        str_t* string2 = string.init("edd256");
        assert(string.equals(string1, string2) != true);
        string.free(string1);
        string.free(string2);
}

void test_substring_1()
{
        str_t* str = string.init("edd255");
        str_t* sub = string.init("d2");
        assert(string.is_substring_of(str, sub));
        string.free(str);
        string.free(sub);
}

void test_substring_2()
{
        str_t* str = string.init("edd255");
        str_t* sub = string.init("d3");
        assert(string.is_substring_of(str, sub));
        string.free(str);
        string.free(sub);
}

void test_index_of_1()
{
        str_t* str = string.init("edd255");
        assert(string.index_of(str, "d") == 1);
        string.free(str);
}

void test_index_of_2()
{
        str_t* str = string.init("edd255");
        assert(string.index_of(str, "6") == -1);
        string.free(str);
}

void test_append_1()
{
        str_t* string1 = string.init("Hello ");
        str_t* string2 = string.init("World!");
        str_t* string3 = string.append(string1, string2);
        str_t* string4 = string.init("Hello World!");
        assert(string3 -> data == string3 -> data);
        string.free(string1);
        string.free(string2);
        string.free(string3);
        string.free(string4);
}

void test_append_2()
{
        str_t* string1 = string.init("");
        str_t* string2 = string.init("");
        str_t* string3 = string.append(string1, string2);
        str_t* string4 = string.init("");
        assert(string3 -> data == string3 -> data);
        string.free(string1);
        string.free(string2);
        string.free(string3);
        string.free(string4);
}


int main()
{
        test_length_1();
        test_length_2();
        test_equality_1();
        test_equality_2();
        test_substring_1();
        test_substring_2();
        test_index_of_1();
        test_index_of_2();
        test_append_1();
        test_append_2();
        return 0;
}

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "src/ds.h"


void test_length_1(void)
{
        str_t* str = string_init("edd255");
        assert(str -> length == 6);
        str->fn->free(str);
}

void test_length_2(void)
{
        str_t* str = string_init("");
        assert(str -> length == 0);
        str->fn->free(str);
}

void test_equality_1(void)
{
        str_t* string1 = string_init("edd255");
        str_t* string2 = string_init("edd255");
        assert(string1->fn->equals(string1, string2));
        string1->fn->free(string1);
        string2->fn->free(string2);
}

void test_equality_2(void)
{
        str_t* string1 = string_init("edd255");
        str_t* string2 = string_init("edd256");
        assert(string1->fn->equals(string1, string2) != true);
        string1->fn->free(string1);
        string2->fn->free(string2);
}

void test_substring_1(void)
{
        str_t* str = string_init("edd255");
        str_t* sub = string_init("d2");
        assert(str->fn->is_substring_of(str, sub));
        str->fn->free(str);
        sub->fn->free(sub);
}

void test_substring_2(void)
{
        str_t* str = string_init("edd255");
        str_t* sub = string_init("d3");
        assert(str->fn->is_substring_of(str, sub));
        str->fn->free(str);
        sub->fn->free(sub);
}

void test_index_of_1(void)
{
        str_t* str = string_init("edd255");
        assert(str->fn->index_of(str, "d") == 1);
        str->fn->free(str);
}

void test_index_of_2(void)
{
        str_t* str = string_init("edd255");
        assert(str->fn->index_of(str, "6") == -1);
        str->fn->free(str);
}

void test_append_1(void)
{
        str_t* string1 = string_init("Hello ");
        str_t* string2 = string_init("World!");
        str_t* string3 = string_init("");
        string3 = string3->fn->append(string1, string2);
        str_t* string4 = string_init("Hello World!");
        assert(string3 -> data == string3 -> data);
        string1->fn->free(string1);
        string2->fn->free(string2);
        string3->fn->free(string3);
        string4->fn->free(string4);
}

void test_append_2(void)
{
        str_t* string1 = string_init("");
        str_t* string2 = string_init("");
        str_t* string3 = string_init("");
        string3 = string3->fn->append(string1, string2);
        str_t* string4 = string_init("");
        assert(string3 -> data == string3 -> data);
        string1->fn->free(string1);
        string2->fn->free(string2);
        string3->fn->free(string3);
        string4->fn->free(string4);
}


int main(void)
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

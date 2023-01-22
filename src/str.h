#include <stddef.h>

typedef struct {
    size_t length;
    char* data;
} str_t;

str_t* string_init(char* data);

void string_free(str_t* self);

str_t* string_prepend(str_t* self, str_t* to_prepend);

str_t* string_append(str_t* self, str_t* to_append);

bool string_equals(str_t* self, str_t* other);

bool string_is_substring_of(str_t* self, str_t* other);

int string_index_of(str_t* self, char* character);

void string_fill(str_t* self, char* character);

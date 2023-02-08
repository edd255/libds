#include <stddef.h>

#define var void

//--- STRINGS -----------------------------------------------------------------

typedef struct vtab_string_t vtab_string_t;
typedef struct str_t str_t;

struct vtab_string_t {
        var (*free)(str_t* self);
        str_t* (*prepend)(str_t*, str_t*);
        str_t* (*append)(str_t*, str_t*);
        bool (*equals)(str_t* self, str_t* other);
        bool (*is_substring_of)(str_t* self, str_t* other);
        int (*index_of)(str_t* self, char* character);
        var (*fill)(str_t* self, char* character);
};

struct str_t {
        const vtab_string_t* fn;
        char* data;
        size_t length;
};

str_t* string_init(char* data);

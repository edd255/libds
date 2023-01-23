#include <stddef.h>

typedef struct {
    size_t length;
    char* data;
} str_t;

typedef struct {
    str_t* (* const init)(char* data);
    void (* const free)(str_t* self);
    str_t* (* const prepend)(str_t*, str_t*);
    str_t* (* const append)(str_t*, str_t*);
    bool (* const equals)(str_t* self, str_t* other);
    bool (* const is_substring_of)(str_t* self, str_t* other);
    int (* const index_of)(str_t* self, char* character);
    void (* const fill)(str_t* self, char* character);
} namespace_string;

extern namespace_string const string;

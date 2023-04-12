#pragma once

//String types

typedef struct String8{
    U8 *str;
    U64 size;
} String8;

typedef struct String16{
    U16 *str;
    U64 size;
} String16;

typedef struct String32{
    U32 *str;
    U64 size;
} String32;

typedef struct String8Node{
    String8Node *next;
    String8 string;
}String8Node;

typedef struct String8List{
    String8Node *first;
    String8Node *last;
    U64 node_count;
    U64 total_size;
}String8List;

typedef struct String8Array{
    U64 count;
    String8 *v;
}String8Array;

typedef struct StringJoin{
    String8 pre;
    String8 mid;
    String8 post;
}StringJoin;

typedef U32 StringMatchFlags;
enum{
    StringMatchFlag_CaseInsensitive = (1<<0),
    StringMatchFlag_RightSideSloppy = (1<<1),
    StringMatchFlag_SlashInsensitve = (1<<2),
    StringMatchFlag_FindLast        = (1<<3),
    StringMatchFlag_KeepEmpties     = (1<<4),
};

typedef struct StringDecode{
    U32 codepoint;
    U32 size;
} StringDecode;

typedef enum IdentifierStyle{
    IdentifierStyle_UpperCamelCase,
    IdentifierStyle_LowerCamelCase,
    IdentifierStyle_UpperCase,
    IdentifierStyle_LowerCase,
} IdentifierStyle;

//Character functions

function B32 char_is_alpha(U8 c);
function B32 char_is_alpha_upper(U8 c);
function B32 char_is_alpha_lower(U8 c);
function B32 char_is_digit(U8 c);
function B32 char_is_symbol(U8 c);
function B32 char_is_whitespace(U8 c);
function B32 char_is_slash(U8 c);
function U8  char_to_upper(U8 c);
function U8  char_to_lower(U8 c);
function U8  char_to_forward_slash(U8 c);

//Constructor functions

function String8 str8(U8 *str, U64 size);
function String8 str8_range(U8 *first, U8 *one_past_last);
function String8 str8_cstring(U8 *cstr);
function String8 str8_prefix(String8 str, U64 size);
function String8 str8_chop(String8 str, U64 amount);
function String8 str8_postfix(String8 str, U64 size);
function String8 str8_skip(String8 str, U64 amount);
function String8 str8_substr_opl(String8 str, U64 first, U64 last);
function String8 str8_sbstr_size(String8 str, U64 first, U64 size);

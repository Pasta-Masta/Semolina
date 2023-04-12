// Character functions

function B32 char_is_alpha(U8 c){
    return (char_is_alpha_upper(c) || char_is_alpha_lower(c));
}

function B32 char_is_alpha_upper(U8 c){
    return(c >= 'A' && c <= 'Z');
}

function B32 char_is_alpha_lower(U8 c){
    return(c >= 'a' && c <= 'z');
}

function B32 char_is_digit(U8 c){
    return(c >= '0' && c <= '9');
}

function B32 char_is_symbol(U8 c){
    return (c == '~' || c == '!'  || c == '$' || c == '%' || c == '^' ||
            c == '&' || c == '*'  || c == '-' || c == '=' || c == '+' ||
            c == '<' || c == '.'  || c == '>' || c == '/' || c == '?' ||
            c == '|' || c == '\\' || c == '{' || c == '}' || c == '(' ||
            c == ')' || c == '\\' || c == '[' || c == ']' || c == '#' ||
            c == ',' || c == ';'  || c == ':' || c == '@');
}

function B32 char_is_whitespace(U8 c){
    return(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f');
}

function B32 char_is_slash(U8 c){
    return(c == '\\' || c == '/');
}

function U8 char_to_upper(U8 c){
    return(('a' <= c && c <= 'z') ? ('A' + (c - 'a')) : c);
}

function U8 char_to_lower(U8 c){
    return(('A' <= c && c <= 'Z') ? ('a' + (c - 'A')) : c);
}

function U8 char_to_forward_slash(U8 c){
    return((c == '\\') ? ('/') : c);
}

// String constructors

function String8 str8(U8 *str, U64 size){
    String8 string;
    string.str = str;
    string.size = size;
    return(string);
}

function String8 str8_range(U8 *first, U8 *one_past_last){
    String8 string;
    string.str = first;
    string.size = (U64)(one_past_last - first);
    return(string);
}

function String8 str8_cstring(U8 *cstr){
    U8 *ptr = cstr;
    for(;*ptr != 0; ptr++);
    String8 string = str8_range(cstr, ptr);
    return(string);
}

function String8 str8_prefix(String8 str, U64 size){
    U64 size_clamped = ClampTop(size, str.size);
    String8 string;
    string.str = str.str;
    string.size = size_clamped;
    return(string);
}

function String8 str8_chop(String8 str, U64 amount){
    U64 amount_clamped = ClampTop(amount, str.size);
    U64 remaining_size = str.size - amount_clamped;
    String8 string;
    string.str = str.str;
    string.size = remaining_size;
    return(string);
}

function String8 str8_postfix(String8 str, U64 size){
    U64 size_clamped = ClampTop(size, str.size);
    U64 skip_by = str.size - size_clamped;
    String8 string;
    string.str = str.str + skip_by;
    string.size = size_clamped;
    return(string);
}

function String8 str8_skip(String8 str, U64 amount){
    U64 amount_clamped = ClampTop(amount, str.size);
    U64 remaining_size = str.size - amount_clamped;
    String8 string;
    string.str = str.str + amount_clamped;
    string.size = remaining_size;
    return(string);
}

function String8 str8_substr_opl(String8 str, U64 first, U64 one_past_last){
    U64 opl_clamped = ClampTop(one_past_last, str.size);
    U64 first_clamped = ClampTop(first, opl_clamped);
    String8 string;
    string.str = str.str + first_clamped;
    string.size = opl_clamped - first_clamped;
    return(string);
}

function String8 str8_sbstr_size(String8 str, U64 first, U64 size){
    String8 string = str8_substr_opl(str, first, first + size);
    return(string);
}


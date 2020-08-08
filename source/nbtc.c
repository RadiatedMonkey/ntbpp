#include "nbtc.h"

#include <stdio>
#include <stdlib>

enum tag_type {
    TAG_End,
    TAG_Byte,
    TAG_Short,
    TAG_Int,
    TAG_Long,
    TAG_Float,
    TAG_Double,
    TAG_Byte_Array,
    TAG_String,
    TAG_List,
    TAG_Compound,
    TAG_Int_Array,
    TAG_Long_Array
};

struct nbtstr {
    size_t len;
    const char* buf;
};

struct nbtstr read_file(const char *path)
{
    FILE* f;
    fopen_s(&f, path, "rb");

    fseek(f, 0, SEEK_END);
    size_t filesize = (size_t)ftell(f);
    rewin(f);

    char* buf = (char*)malloc(filesize);
    if (!buf) {
        fclose(f);
        struct nbtstr str = { 0, NULL };
        return str;
    }

    fread_s(buf, filesize, sizeof(char), filesize, f);

    fclose(f);
    struct nbtstr str = { filesize, buf };
    return str;
}

void parse_file(const char *path)
{
    struct nbtstr str = read_file(path);
    
    

    free(str.buf);
}
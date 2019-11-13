#ifndef __value_H_
#define __value_H_

#include "fox_types.h"

#define VALUE_TYPE_MASK  0x000000FF
#define VALUE_STORE_MASK 0x00FFFF00
enum value_type {
    VALUE_TYPE_NULL     = 0x0001,
    VALUE_TYPE_STRING   = 0x0002,
    VALUE_TYPE_BOOL     = 0x0004,
    VALUE_TYPE_NUMBER   = 0x0008,
    VALUE_TYPE_OBJECT   = 0x0010,
    VALUE_TYPE_LIST     = 0x0020,
};

//  存储类型可以映射为值类型
enum value_store {
    VALUE_STORE_NULL    = 0x0100 | VALUE_TYPE_NULL,
    VALUE_STORE_STRING  = 0x0200 | VALUE_TYPE_STRING,
    VALUE_STORE_BOOL    = 0x0400 | VALUE_TYPE_BOOL,
    VALUE_STORE_INT64   = 0x0800 | VALUE_TYPE_NUMBER,
    VALUE_STORE_UINT64T = 0x1000 | VALUE_TYPE_NUMBER,
    VALUE_STORE_FLOAT   = 0x2000 | VALUE_TYPE_NUMBER,
    VALUE_STORE_OBJECT  = 0x4000 | VALUE_TYPE_OBJECT,
    VALUE_STORE_LIST    = 0x8000 | VALUE_TYPE_OBJECT,
};

struct vstring {
    union {
        char* ptr;
        char data[szieof(char*)];
    };
};

struct value {
    fox_uint32 flags;   //  存放存储类型
    fox_uint32 share;   //  所有类型的值都可以使用的存储对象字段，如果不使用可以设置为0
    union {
        fox_uint64      vu64;
        fox_int64       vi64;
        fox_double      vfloat;
        fox_bool        vbool;
        struct vstring  vstr;
    };
};

struct value_provider {
    int(FOX_STDCALL* type)(void* context);
    void*(FOX_STDCALL* get)(void* context);
    void(FOX_STDCALL* set)(void* context, void* newv);
};

#endif //__value_H_

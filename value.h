#ifndef __value_H_
#define __value_H_

#include "fox_types.h"

#define VALUE_TYPE_MASK  0x000000FF
#define VALUE_STORE_MASK 0x00FFFF00
enum value_type {
    VALUE_TYPE_NULL     = 0x00000001,
    VALUE_TYPE_STRING   = 0x00000002,
    VALUE_TYPE_BOOL     = 0x00000004,
    VALUE_TYPE_NUMBER   = 0x00000008,
    VALUE_TYPE_OBJECT   = 0x00000010,
    VALUE_TYPE_LIST     = 0x00000020,
};

//  存储类型可以映射为值类型
enum value_store {
    VALUE_STORE_NULL    = 0x00000100,
    VALUE_STORE_STRING  = 0x00000200,
    VALUE_STORE_BOOL    = 0x00000400,
    VALUE_STORE_INT64   = 0x00000800,
    VALUE_STORE_UINT64T = 0x00001000,
    VALUE_STORE_DOUBLE  = 0x00002000,
    VALUE_STORE_FLOAT   = 0x00004000,
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
        fox_uint64 vu64;
        fox_int64 viu64;
        fox_double vf64;
        fox_float vf32;

    };
    
};

#endif //__value_H_

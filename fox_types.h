#ifndef fox_types
#define fox_types




/// 定义了外部引用宏
#if  defined(__cplusplus)
#define FOX_EXTERN  extern  "C"
#else
#define FOX_EXTERN  extern
#endif




/// 定义了符号导入和导出宏
#if   defined(_WIN32)
#ifdef FOX_EXPORTS
#define FOX_API __declspec(dllexport)
#else
#define FOX_API __declspec(dllimport)
#endif
#else
#define FOX_API
#endif





/// 定义了统一的STDCALL的调用协定
#if   defined(_WIN32)
#define FOX_STDCALL    __stdcall
#else
#define FOX_STDCALL     __attribute__((__stdcall__))
#endif



//  补齐Windows下的一些差异
#if defined(_WIN32)
#define inline __inline
#endif




//  固定宽度类型适配
typedef char                fox_int8;
typedef short               fox_int16;
typedef int                 fox_int32;
typedef __int64             fox_int64;
typedef unsigned char       fox_uint8;
typedef unsigned short      fox_uint16;
typedef unsigned int        fox_uint32;
typedef unsigned __int64    fox_uint64;




//  定义一个错误码,多用于返回值，统一使用：0表示成功，其他值表示失败
#define fox_errno           int
#define fox_true            (1)
#define fox_false           (0)




/// 定义了一个适用于C语言的编译期断言宏，用于对编译环境进行一些基本的检查
///@{
#if     defined(__cplusplus)
#define FOX_STATIC_ASSERT(expr,message)     static_assert(expr,message)
#else
#if   defined(_MSC_VER)
#define FOX_STATIC_ASSERT(expr,message)     typedef char __SMQ_STATIC_ASSERT[(expr)?1:-1]
#else
#define FOX_STATIC_ASSERT(expr,message)     _Static_assert(expr,message)
#endif
#endif



FOX_STATIC_ASSERT((1 == sizeof(fox_int8)), "");
FOX_STATIC_ASSERT((2 == sizeof(fox_int16)), "");
FOX_STATIC_ASSERT((4 == sizeof(fox_int32)), "");
FOX_STATIC_ASSERT((8 == sizeof(fox_int64)), "");
FOX_STATIC_ASSERT((1 == sizeof(fox_uint8)), "");
FOX_STATIC_ASSERT((2 == sizeof(fox_uint16)), "");
FOX_STATIC_ASSERT((4 == sizeof(fox_uint32)), "");
FOX_STATIC_ASSERT((8 == sizeof(fox_uint64)), "");
FOX_STATIC_ASSERT(sizeof(fox_int32) == sizeof(fox_errno), "");

#endif//fox_types


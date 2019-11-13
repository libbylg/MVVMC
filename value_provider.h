#ifndef __value_provider_H_
#define __value_provider_H_

#include "fox_types.h"

//  value_provider ʵ������ֵ��Ӧ����
struct value_provider {
    void* ctx;
    int(FOX_STDCALL* type)(void* context);
    void*(FOX_STDCALL* get)(void* context);
    void(FOX_STDCALL* set)(void* context, void* newv);
};



#endif //__value_provider_H_


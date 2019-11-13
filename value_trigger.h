#ifndef __trigger_H_
#define __trigger_H_

#include "fox_types.h"


//  value_trigger 实现了一个对象订阅模型
struct value_trigger {
    void* ctx;
    int(FOX_STDCALL*    init    )(void* context, void* curv);
    int(FOX_STDCALL*    exit    )(void* context, void* curv);
    int(FOX_STDCALL*    before  )(void* context, void* newv, void* oldv);
    void(FOX_STDCALL*   after   )(void* context, void* newv);
};



#endif //__react_H_

#ifndef __trigger_H_
#define __trigger_H_

#include "fox_types.h"

//  trigger 实现了一个对象订阅模型

struct value_provider {
    int (*type)();
    void* (*get)();
    void (*set)(void* newv);
};

typedef int  (*TRIGGER_NOTIFY_BEFORE)(void* ctx, void* newv, void* oldv);
typedef void (*TRIGGER_NOTIFY_AFTER )(void* ctx, void* newv);
FOX_EXTERN int trigger_modify   (struct trigger* t, void* oldv, void* newv);
FOX_EXTERN int trigger_before   (struct trigger* t, TRIGGER_NOTIFY_BEFORE notify, void* ctx);
FOX_EXTERN int trigger_after    (struct trigger* t, TRIGGER_NOTIFY_AFTER notify, void* ctx);

#endif //__react_H_

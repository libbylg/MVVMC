#ifndef __trigger_H_
#define __trigger_H_


//  trigger ʵ����һ��������ģ��

typede int (*TRIGGER_NOTIFY)(void* ctx, void* oldv, void* newv);
int trigger_modify(struct trigger* t, void* oldv, void* newv);
int trigger_before(struct trigger* t, TRIGGER_NOTIFY notify, void* ctx);
int trigger_after (struct trigger* t, TRIGGER_NOTIFY notify, void* ctx);

#endif //__react_H_


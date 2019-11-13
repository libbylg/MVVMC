#ifndef __mvvmc_H_
#define __mvvmc_H_

struct vm;

struct vm*  vm_new                  (char* name);
int         vm_register_provider    (struct vm* p, char* name, struct value_provider* provider, void* ctx);
int         vm_add_trigger          (struct vm* p, char* name, struct value_trigger*  trigger,  void* ctx);


#endif //__mvvmc_H_


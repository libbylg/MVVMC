#include "mvvmc.h"


struct binder_trigger {
    struct list_head head;
    struct value_trigger trigger;
};

struct binder {
    struct hash_node head;
    struct str name;
    struct value_provider provider;
    struct list_head triggers;
};

struct vm {
    struct hash_node head;
    struct str name;
    struct hash_map binders;
};

struct vm* vm_new(char* name)
{
}

int vm_register_provider(struct vm* p, char* name, struct value_provider* provider)
{
}

int vm_add_trigger(struct vm* p, char* name, struct value_trigger* trigger)
{

}


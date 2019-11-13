#ifndef __list_H_
#define __list_H_

//#include "fox_libc.h"
//#include "fox_types.h"

struct list_head {
    struct list_head* next;
    struct list_head* prev;
};

static inline void list_init(struct list_head* n)
{
    n->next = n;
    n->prev = n;
}

static inline void __list_add(struct list_head* prev, struct list_head* next, struct list_head* newi)
{
    newi->next = next;
    newi->prev = prev;

    prev->next = newi;
    next->prev = newi;
}

static inline void list_add(struct list_head* h, struct list_head* newi)
{
    __list_add(h, h->next, newi);
}

static inline void list_add_tail(struct list_head* h, struct list_head* newi)
{
    __list_add(h->prev, h, newi);
}

static inline struct list_head* list_del(struct list_head* i)
{
    i->prev->next = i->next;
    i->next->prev = i->prev;
    i->next = i;
    i->prev = i;
    return i;
}

static inline int list_empty(struct list_head* list)
{
    return list->next == list;
}

static inline void list_splice(struct list_head* list, struct list_head* list_from)
{
    if (list_empty(list_from)) {
        return;
    }

    struct list_head* first = list_from->next;
    struct list_head* last = list_from->prev;

    first->prev = list;
    last->next = list->next;

    list->next->prev = last;
    list->next = first;

    list_init(list_from);
}

static inline void list_splice_tail(struct list_head* list, struct list_head* list_from)
{
    if (list_empty(list_from)) {
        return;
    }

    struct list_head* first = list_from->next;
    struct list_head* last = list_from->prev;

    last->next = list;
    first->prev = list->prev;

    list->prev->next = first;
    list->prev = last;

    list_init(list_from);
}

#define container_of(ptr, type, member) ((type*)((char*)(ptr)-offsetof(type, member)))

#define list_entry(ptr, type, member) (fox_container_of(ptr, type, member))

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)

#endif //__list_H_

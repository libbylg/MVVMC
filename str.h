#ifndef __str_H_
#define __str_H_

struct str {
    int len;
    unsigned hash;
    union {
        char* ptr;
        char data[sizeof(char*)];
	};
};



#endif //__str_H_

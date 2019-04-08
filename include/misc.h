#ifndef MISC_H_
#define MISC_H_

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define ARRMAXIDX(x) (ARRAY_LEN(x) - 1)

#define offsetof(TYPE,MEMBER) ((u16) &((TYPE *)0)->MEMBER)
#define OFFSETOFA(s,m) ((size_t)&(((s *)0)->m))
#define OFFSETOFB(s,m) ((size_t)(unsigned long)&(((s *)0)->m))
#define OFFSETOFC(s,memb) ((size_t)((char *)&((s *)0)->memb-(char *)0))

#define MIN(a,b) ((a)>(b))?(b):(a)
#define MAX(a,b) ((a)<(b))?(b):(a)

#endif /* MISC_H_ */

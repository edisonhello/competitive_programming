#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

int travelTime(int N, int M, int L, int A[], int B[], int T[]);

typedef int (*travelTimeFunction)(int N, int M, int L, int A[], int B[], int T[]);

#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */

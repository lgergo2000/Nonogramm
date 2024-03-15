#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H
#include <stdlib.h>
#include <stdio.h>


typedef int bool;
#define TRUE 1
#define FALSE 0

#define DEFINE_GENERIC_LIST_FUNCTIONS_HEADER(typename, type) \
    typedef struct { \
        type* data; \
        int length; \
    } typename; \
    \
    typename Init##typename(int length); \
    \
    void Free##typename(typename* list); \
    \
    void Print##typename(typename* list);\
    \
    typename typename##SliceByRightIndex(typename list, int end_index);\
    \
    typename typename##SliceByLeftIndex(typename list, int start_index);\
    \
    typename typename##SliceByBothIndex(typename list, int start_index, int end_index);\
    \
    void AppendTo##typename(typename* list, type element);\


#define IMPLEMENT_GENERIC_LIST_FUNCTIONS(typename, type) \
    typename Init##typename(int length) { \
        typename list; \
        list.data = (type *)calloc(length, sizeof(type)); \
        list.length = length; \
        return list; \
    } \
    \
    void Free##typename(typename* list) { \
        free(list->data); \
    } \
    \
    void Print##typename(typename* list) { \
        printf("["); \
        for(int i = 0; i<list->length; i++) { \
            Print##type(&(list->data[i])); \
        } \
        printf("]\n"); \
    }\
    typename typename##SliceByRightIndex(typename list, int end_index)\
    {\
        if(end_index >= list.length) return list;\
        if(end_index <= 0 || list.length == 0) return Init##typename(0);\
    \
        typename res = Init##typename(end_index);\
        for(int i = 0; i < end_index; i++)\
        {\
            res.data[i] = list.data[i];\
        }\
        return res;\
    }\
    typename typename##SliceByLeftIndex(typename list, int start_index)\
    {\
        if(start_index >= list.length || list.length == 0) return Init##typename(0);\
        if(start_index <= 0) return list;\
    \
        typename res = Init##typename(list.length - start_index);\
        for(int i = 0; i < res.length; i++)\
        {\
            res.data[i] = list.data[i+start_index];\
        }\
        return res;\
    }\
    typename typename##SliceByBothIndex(typename list, int start_index, int end_index)\
    {\
        typename res = typename##SliceByLeftIndex(list, start_index);\
        return typename##SliceByRightIndex(res, end_index - start_index);\
    }\
    void AppendTo##typename(typename* list, type element)\
    {\
        (*list).length++;\
        (*list).data = (type*)realloc((*list).data, (*list).length * sizeof(type));\
        if((*list).data == NULL)\
        {\
            (*list) = Init##typename(0);\
            return;\
        }\
        (*list).data[(*list).length - 1] = element;\
    }\

#endif

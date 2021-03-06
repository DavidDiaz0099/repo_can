/*******************************************************************************/
/**
\file       MemAlloc.h
\brief      Memowy Allocation header file
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
#ifndef __MEMALLOC_H
#define  __MEMALLOC_H

#include "MemAlloc_Types.h"

extern void MemAllocInit(const MemAllocConfigType *MemAllocConfigParam);
extern void * MemAlloc(u32 size);
extern void MemAllocInit(const MemAllocConfigType *MemAllocConfigParam);  //Yo la puse
extern void * MemAlloc(u32 size);  //YO la puse

#endif /* __MEMALLOC_H */

/*
** MALLOC_FAILED.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Mon Dec 29 18:10:35 2014 thomas rieux-laucat
** Last update Mon Dec 29 18:13:36 2014 thomas rieux-laucat
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

static void* (*real_malloc)(size_t)=NULL;

static void mtrace_init(void)
{
  real_malloc = dlsym(RTLD_NEXT, "malloc");
  if (NULL == real_malloc) {
    fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
  }
}

void *malloc(size_t size)
{
  if(real_malloc==NULL) {
    mtrace_init();
  }

  void *p = NULL;
  fprintf(stderr, "malloc(%zd) = ", size);
  p = real_malloc(size);
  fprintf(stderr, "%p\n", p);
  return p;
}

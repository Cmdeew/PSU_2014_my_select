/*
** my_malloc.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Mon Dec 22 18:26:04 2014 thomas rieux-laucat
** Last update Wed Dec 24 18:49:11 2014 thomas rieux-laucat
*/

#include <stdlib.h>
#include <stdio.h>

void		*xmalloc(size_t n)
{
  int	*p;
  
  p = malloc(n);
  if (p == NULL)
    {
      printf("Oups something wrong.. SCHSCHSCHSCHSC a null malloc appear oh no ! trow a pokeball for stop him\n");
      exit(1);
    }
}

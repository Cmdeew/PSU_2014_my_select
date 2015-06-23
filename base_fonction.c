/*
** base_fonction.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Mon Dec 22 18:38:29 2014 thomas rieux-laucat
** Last update Sun Jan 11 19:48:06 2015 thomas rieux-laucat
*/

#include <unistd.h>
#include "include/list.h"

int	my_strlen(char *str)
{
  int	i;
  
  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  if (FD == 1)
    write(FD, str, my_strlen(str));
  else
    exit(1);
}

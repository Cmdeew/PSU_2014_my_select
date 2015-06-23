/*
** my_fonction_exit.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Jan  7 15:15:03 2015 thomas rieux-laucat
** Last update Sun Jan 11 21:37:24 2015 thomas rieux-laucat
*/

#include "include/list.h"

int	exit_program(char *buffer)
{
  if (buffer[0] == 27 && buffer[1] == 0)
    {
      clean_screen();
      my_putstr("Echap pressed.\n");
      return (0);
    }
  else if (buffer[0] == 4)
    {
      clean_screen();
      my_putstr("Ctrl+d EXIT\n");
      return (0);
    }
  return (1);
}

int		send_selection(t_list *list)
{
  t_list	*it;

  clean_screen();
  it = list;
  it = list->prev;
  while (it != list)
    {
      if (it->i == 1)
	{
	  my_putstr(it->data);
	  my_putchar(' ');
	}
      it = it->prev;
    }
  return (1);
}

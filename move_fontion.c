/*
** move_fontion.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
**
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Fri Jan  9 19:09:20 2015 thomas rieux-laucat
** Last update Sun Jan 11 21:13:47 2015 thomas rieux-laucat
*/

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "include/list.h"

void	set_curs(int y)
{
  char	*cap;
  char  *ret;

  cap = tgetstr("cm", NULL);
  ret = tgoto(cap, 0, y);
  tputs(ret, 0, my_outc);
}

void		move_up(t_list *list)
{
  t_list	*tmp;
  
  
  tmp = list->next;
  while (tmp && tmp->current == 0)
    tmp = tmp->next;
  tmp->current = 0;
  if (tmp->next != list)
    tmp->next->current = 1;
  else
    tmp->next->next->current = 1;
  refresh_screen(&list);
}

void		move_down(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp && tmp->current == 0)
    tmp = tmp->next;
  if (tmp->prev != list)
    tmp->prev->current = 1;
  else
    tmp->prev->prev->current = 1;
  tmp->current = 0;
  refresh_screen(&list);
}

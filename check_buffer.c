/*
** check_buffer.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
**
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Wed Jan  7 14:41:02 2015 thomas rieux-laucat
** Last update Sun Jan 11 21:42:04 2015 thomas rieux-laucat
*/

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "include/list.h"

void    init_buff(char  *buffer)
{
  buffer[0] = 0;
  buffer[1] = 0;
  buffer[2] = 0;
}

void	refresh_screen(t_list **list)
{
  clean_screen();
  show_list(list);
}

void	reverse_both(char *str)
{
  if (tputs(tgetstr("so", NULL), 0, my_outc) == -1)
    exit(1);
  if (tputs(tgetstr("us", NULL), 0, my_outc) == -1)
    exit(1);
  my_putstr(str);
  tputs(tgetstr("ue", NULL), 0, my_outc);
  tputs(tgetstr("se", NULL), 0, my_outc);
}

int		check_buffer(t_list *tmp, char *buffer)
{
  if (buffer[0] == 27 && buffer[2] == 65)
    move_up(tmp);
  else if (buffer[0] == 27 && buffer[2] == 66)
    move_down(tmp);
  else if (buffer[0] == 32 && buffer[2] == 0 && buffer[3] == 0)
    select_node(tmp);
  else if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
    {
      if ((delete_node(tmp)) == 1)
	return (1);
    }
  if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
    {
      if ((send_selection(tmp)) == 1)
	return (1);
    }
  if ((exit_program(buffer)) == 0)
    return (1);
  return (0);
}

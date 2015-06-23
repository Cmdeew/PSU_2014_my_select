/*
** my_fonction.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Jan  7 15:03:55 2015 thomas rieux-laucat
** Last update Sun Jan 11 21:12:40 2015 thomas rieux-laucat
*/

#include <unistd.h>
#include <curses.h>
#include <term.h>
#include "include/list.h"

void    my_putchar(char c)
{
  write(FD, &c, 1);
}

int     my_outc(int c)
{
  my_putchar(c);
  return (0);
}

void    clean_screen()
{
  char  *res;

  if ((res = tgetstr("cl", NULL)) == NULL)
    exit(1);
  tputs(res, 0, my_outc);
}

void    reverse_vid(char *str)
{
  if ((tputs(tgetstr("mr", NULL), 0, my_outc)) == -1)
    exit(1);
  my_putchar('\r');
  my_putstr(str);
  tputs(tgetstr("me", NULL), 0, my_outc);
}

void    underline(char *str)
{
  if ((tputs(tgetstr("us", NULL), 0, my_outc)) == -1)
    exit(1);
  my_putchar('\r');
  my_putstr(str);
  tputs(tgetstr("ue", NULL), 0, my_outc);
}

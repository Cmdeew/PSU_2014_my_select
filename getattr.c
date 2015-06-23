/*
** getattr.c for my_select.c in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
**
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Wed Dec 17 16:48:17 2014 thomas rieux-laucat
** Last update Tue Jun 23 17:38:59 2015 Thomas-Rieux-Laucat
*/

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "include/list.h"

int			display(int ac, char **av)
{
  char	    buffer[3];
  int		y;
  t_list	*list;
  t_list	*tmp;

  y = 0;
  clean_screen();
  list = my_params_in_list(ac, av);
  tmp = list;
  tmp->current = 1;
  show_list(&list);
  set_curs(y);
  if (tputs(tgetstr("vi", NULL), 0, my_outc) == -1)
    return (1);
  while(1)
    {
      init_buff(buffer);
      read(0, buffer, 3);
      if ((check_buffer(tmp, buffer)) == 1)
	return (1);
    }
  trow_list(&tmp);
  trow_list(&list);
  if (tputs(tgetstr("ve", NULL), 0, my_outc) == -1)
    return (1);
  return (0);
}

char	*get_env(char **env)
{
  int	i;

  i = 0;
  if (env == NULL || env[0] == NULL)
    return (NULL);
  while (env[i])
    {
      if (env[i][0] == 'T' && env[i][1] == 'E' && env[i][2] == 'R'
	  && env[i][3] == 'M' && env[i][4] == '=')
	return (&(env[i][5]));
      i = i + 1;
    }
  return (NULL);
}

int		set_terminal(struct termios t_new)
{
  t_new.c_lflag &= ~ICANON;
  t_new.c_lflag &= ~ECHO;
  t_new.c_cc[VMIN] = 1;
  t_new.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &t_new) == -1)
    return (-1);
  return (0);
}

int			main(int argc, char **argv, char **env)
{
  char			*name_term;
  struct termios	t_old;
  struct termios	t_new;

  if (argc == 1)
    return (1);
  if ((name_term = get_env(env)) == NULL)
    name_term = "xterm";
  tgetent(NULL, name_term);
  if (tcgetattr(0, &t_new) == -1)
    return (1);
  t_old = t_new;
  if ((set_terminal(t_new)) == -1)
    return (1);
  if ((display(argc, argv)) == 1)
    return (1);
  if ((tcsetattr(0, TCSANOW, &t_old)) == -1)
    return (1);
  return (0);
}

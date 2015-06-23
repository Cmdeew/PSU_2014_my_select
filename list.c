/*
** list.c for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
**
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Fri Dec 19 13:24:58 2014 thomas rieux-laucat
** Last update Sun Jan 11 20:09:47 2015 thomas rieux-laucat
*/

#include "include/list.h"
#include <stdio.h>
#include <stdlib.h>

t_list		*create_list()
{
  t_list	*root;

  if ((root = malloc(sizeof(*root))) == NULL)
    exit(1);
  if (root == NULL)
    exit(1);
  root->prev = root;
  root->next = root;
  return (root);
}

void		trow_list(t_list **list)
{
  t_list	*tmp;

  while (*list)
    {
      tmp = (*list)->next;
      free(*list);
      *list = tmp;
    }
}

int		push(t_list **list, char *val)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (1);
  if (new != NULL)
    {
      new->data = val;
      new->i = 0;
      new->current = 0;
      new->prev = (*list);
      new->next = (*list)->next;
      (*list)->next->prev = new;
      (*list)->next = new;
    }
  return (0);
}

t_list          *my_params_in_list(int ac, char **val)
{
  int           i;
  t_list        *list;

  i = 1;
  list = create_list();
  while (i < (ac))
    {
      push(&list, val[i]);
      i++;
    }
  return (list);
}

void		show_list(t_list **list)
{
  t_list	*it;

  it  = (*list);
  it = it->prev;
  while (it != (*list))
    {
      if (it->i == 1 && it->current == 0)
	reverse_vid(it->data);
      else if (it->current == 1 && it->i == 0)
	underline(it->data);
      else if (it->current == 1 && it->i == 1)
	reverse_both(it->data);
      else
	my_putstr(it->data);
      my_putchar('\n');
      it = it->prev;
    }
}

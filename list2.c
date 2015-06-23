/*
** list2.c for my_select.c in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
** 
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Sat Jan 10 12:33:58 2015 thomas rieux-laucat
** Last update Sun Jan 11 20:28:34 2015 thomas rieux-laucat
*/

#include <stdlib.h>
#include "include/list.h"

char            *last_node(t_list **list)
{
  t_list        *tmp;
  
  
  tmp = *list;
  tmp = tmp->next;
  while (tmp != (*list));
  return (tmp->data);
}

int		nb_elem_list(t_list *list)
{
  t_list	*it;
  int		i;
  
  it = list;
  it = list->next;
  i = 0;
  while (it != list)
    {
      i++;
      it = it->next;
    }
  return (i);
}

int		delete_node(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  if ((nb_elem_list(list)) != 0)
    {
      while (tmp && tmp->current == 0)
	tmp = tmp->next;
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
      if (tmp->next != list)
	tmp->next->current = 1;
      else
	tmp->next->next->current = 1;
    }
  else 
    return (1);
  free(tmp);
  refresh_screen(&list);
  return (0);
}

void            select_node(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp && tmp->current == 0)
    tmp = tmp->next;
  if (tmp->i == 1)
    tmp->i = 0;
  else
    {
      tmp->i = 1;
      tmp->current = 0;
      if (tmp->prev != list)
        tmp->prev->current = 1;
      else
        tmp->prev->prev->current = 1;
    }
  refresh_screen(&list);
}

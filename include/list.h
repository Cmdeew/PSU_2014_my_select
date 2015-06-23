/*
** list.h for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
**
** Made by thomas rieux-laucat
** Login   <rieux-_t@epitech.net>
**
** Started on  Fri Dec 19 13:20:42 2014 thomas rieux-laucat
** Last update Sun Jan 11 21:56:20 2015 thomas rieux-laucat
*/


#ifndef LIST_H_
# define LIST_H_

#include <stdlib.h>

typedef struct		s_list
{
  char			*data;
  int			i;
  int			current;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

 /* List ***********************/
/******************************/
t_list	*create_list();
void	*xmalloc(size_t);
int	display(int, char **);
t_list	*my_params_in_list(int , char **);
void	my_show_list(t_list **);
void	trow_list(t_list **);
int	push(t_list **, char *);
char	*last_node(t_list **);
int	delete_node(t_list *);
void	show_list(t_list **);
void	select_node(t_list *);


 /* Termcap ******************/
/****************************/
void	my_putchar(char);
int	my_outc(int);
void	clean_screen();
void	reverse_vid(char *);
void	underline(char *);
int	exit_program(char *);
void	inti_buff(char *);
void	reverse_both(char *);
void	refresh_screen(t_list **);
void	set_curs(int);
void	move_up(t_list *);
void	move_down(t_list*);
int	check_buffer(t_list *, char *);
void	init_buff(char *);
int	send_selection(t_list *);

 /* Base fonction ***********/
/***************************/

void	my_putstr(char *);
int	my_strlen(char *);
int	my_strncmp(char *, char *, int);

#define FD 1

#endif /* !LIST_H_ */

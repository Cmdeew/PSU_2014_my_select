##
## Makefile for my_select in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_my_select
## 
## Made by thomas rieux-laucat
## Login   <rieux-_t@epitech.net>
## 
## Started on  Thu Dec 18 00:10:12 2014 thomas rieux-laucat
## Last update Sun Jan 11 21:56:52 2015 thomas rieux-laucat
##

SRC	=	base_fonction.c \
		list.c \
		list2.c \
		my_strncmp.c \
		check_buffer.c \
		my_fonction.c \
		my_fonction_exit.c \
		move_fontion.c \
		getattr.c

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-W -Wall -Wextra

OBJS	=	$(SRC:.c=.o)

NAME	=	myselect

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) -lncurses

clean	:	
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

##
## Makefile for  in /home/mathias/Bureau/projet_epitech/synthèse/SBMLparser
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Mon Jun 12 10:03:34 2017 Mathias
## Last update Wed Jun 14 16:44:25 2017 Mathias
##

SRC	=	src/test.c		\
		src/algo.c		\
		src/gnl.c		\
		src/is_reaction.c	\
		src/part_disp.c		\
		src/sort_file.c		\
		src/add_elem.c		\
		src/disp_elem.c

OBJ	=	$(SRC:.c=.o)

NAME	=	SBMLparser

CFLAGS	=	-W -Wall -Werror -Wextra -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

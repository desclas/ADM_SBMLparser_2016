/*
** parser.h for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 18:50:27 2017 Mathias
** Last update Wed Jun 14 16:35:12 2017 Mathias
*/

#ifndef PARSER_H_
# define PARSER_H_

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

# define REACTION 3
# define SPECIES 2
# define REFERENCE 1
# define FAIL -1

typedef struct s_elem
{
  char *name;
  char **part;
}		t_elem;

int my_len(char *str);
char *my_gnl(int fd);
void inistr(char *str,int max);
char **append_chartab(char **tab, char *str);
void sort_file(char **tab);
int my_cmp_mod(char *tab, char *str);
void sort_tab_until(char **tab, int begin, int end);
int help(char *name);
void disp_auto(char **tab);
int what_is_it(char **tab, char *str);
void is_species(char **tab, char *str);
void is_reaction(char **tab, char *search, int arge);
void algo(char **tab, char *search, int arge);
int check_line(char *tab, char *c);
char *append_char(char *str, char c);
void add_elem(t_elem **elem, char *str, int *count);
t_elem **append_elem(t_elem **elem);
int t_or_f(char *str);
char *have_reaction(char *tab);
int safe(char *str);

#endif /* !PARSER_H_ */

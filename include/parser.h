/*
** parser.h for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 18:50:27 2017 Mathias
** Last update Mon Jun 12 19:07:35 2017 Mathias
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

char *my_gnl(int fd);
void inistr(char *str,int max);
char **append_chartab(char **tab, char *str);
void sort_file(char **tab);
int my_cmp_mod(char *tab, char *str);
void sort_tab_until(char **tab, int begin, int end);
int help(char *name);
void disp_auto(void);
int what_is_it(char **tab, char *str);
void is_species(char **tab, char *str);
void is_reaction(char **tab, char *search, int arge);
void algo(char **tab, char *search, int arge);

#endif /* !PARSER_H_ */

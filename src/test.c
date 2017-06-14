/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/SBMLparser
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 10:21:19 2017 Mathias
** Last update Wed Jun 14 16:52:00 2017 Mathias
*/

#include "parser.h"

int t_or_f(char *str)
{
  int i;

  i = 0;
  while (str[++i] != '\0' && my_cmp_mod(&str[i], "reversible=") != 0);
  i += 13;
  if (my_cmp_mod(&str[i], "false") == 0)
    return (0);
  return (1);
}

void free_tab(char **tab, int st)
{
  int i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
  exit(st);
}

void option_sequel(char **ac, char **tab, int *opt)
{
  if (opt[3] == 1)
    printf("en construction\n");
  else if (opt[0] == 1)
    {
      if (opt[1] == 0)
	disp_auto(tab);
      else
	{
	  if (opt[2] == 0)
	    algo(tab, ac[opt[1]], 0);
	  else
	    algo(tab, ac[opt[1]], 1);
	}
    }
  else
    disp_auto(tab);
}

void option(int av, char **ac, char **tab)
{
  int opt[4];
  int i;

  opt[0] = 0;
  opt[1] = 0;
  opt[2] = 0;
  opt[3] = 0;
  i = 0;
  while (++i != av)
    if (my_cmp_mod(ac[i], "-i") == 0)
      {
	opt[0] = 1;
	if (i != av - 1 && my_cmp_mod(ac[i + 1], "-e") != 0 &&
	    my_cmp_mod(ac[i + 1], "-json") != 0)
	  opt[1] = i + 1;
      }
    else if (my_cmp_mod(ac[i], "-e") == 0)
      opt[2] = 1;
    else if (my_cmp_mod(ac[i], "-json") == 0)
      opt[3] = 1;
  option_sequel(ac, tab, opt);
}

int main(int av, char **ac)
{
  int fd;
  char *str;
  char **tab;

  tab = malloc(sizeof(char *));
  tab[0] = NULL;
  if (av >= 2)
    {
      if (my_cmp_mod(ac[1], "-h") == 0)
	return (help(ac[0]));
      if ((fd = open(ac[1], O_RDONLY)) == -1)
	return (84);
      while ((str = my_gnl(fd)) != NULL)
	tab = append_chartab(tab, str);
      close(fd);
      sort_file(tab);
      option(av, ac, tab);
      return (0);
    }
  return (84);
}

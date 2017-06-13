/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/SBMLparser
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 10:21:19 2017 Mathias
** Last update Tue Jun 13 09:45:17 2017 mathias descoins
*/

#include "parser.h"

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

void option_sequel(char **ac, char **tab)
{
  if (my_cmp_mod(ac[2], "-i") == 0 && my_cmp_mod(ac[3], "-e") != 0 &&
      my_cmp_mod(ac[3], "-json") != 0 && my_cmp_mod(ac[4], "-e") == 0 &&
      my_cmp_mod(ac[5], "-json") == 0)
    printf("en construction\n");
  else
    free_tab(tab, 84);
}

void option(int av, char **ac, char **tab)
{
  if (av == 2)
    disp_auto();
  else if (av == 5)
    {
      if (my_cmp_mod(ac[4], "-e") == 0 && my_cmp_mod(ac[2], "-i") == 0 &&
	  my_cmp_mod(ac[3], "-e") != 0 && my_cmp_mod(ac[3], "-json") == 0)
	algo(tab, ac[3], 1);
      else if (my_cmp_mod(ac[4], "-json") == 0 && my_cmp_mod(ac[2], "-i") == 0
	       && my_cmp_mod(ac[3], "-e") != 0 &&
	       my_cmp_mod(ac[3], "-json") != 0)
	printf("en construction\n");
      else
	free_tab(tab, 84);
    }
  else if (av == 4)
    {
      if (my_cmp_mod(ac[2], "-i") == 0 && my_cmp_mod(ac[3], "-e") != 0 &&
	  my_cmp_mod(ac[3], "-json") != 0)
	algo(tab, ac[3], 0);
      else
	free_tab(tab, 84);
    }
  else if (av == 6)
    option_sequel(ac, tab);
  free_tab(tab, 0);
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

/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/SBMLparser
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 10:21:19 2017 Mathias
** Last update Tue Jun 13 08:50:14 2017 Mathias
*/

#include "parser.h"

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
      if (av == 2)
	disp_auto();
      if (av == 5)
	{
	  if (my_cmp_mod(ac[4], "-e") == 0)
	    algo(tab, ac[3], 1);
	  else if (my_cmp_mod(ac[3], "-json") == 0)
	    printf("en construction\n");
	}
      if (av == 4)
	{
	  if (my_cmp_mod(ac[2], "-i") == 0)
	    algo(tab, ac[3], 0);
	  else if (my_cmp_mod(ac[2], "-e") == 0)
	    disp_auto();
	}
      int i;
      for (i = 0; tab[i] != NULL; i += 1)
	{
	  /* printf("%s\n", tab[i]); */
	  free(tab[i]);
	}
      free(tab);
      return (0);
    }
  return (84);
}

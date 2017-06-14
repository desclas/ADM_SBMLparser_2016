/*
** algo.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 19:04:05 2017 Mathias
** Last update Wed Jun 14 07:38:36 2017 mathias descoins
*/

#include "parser.h"

int my_getdigit_until(char *str, char stop)
{
  int i;
  int res;

  i = 0;
  res = 0;
  while (str[i] != '\0' && str[i] != stop)
    {
      res = (res * 10) + (str[i] - 48);
      i += 1;
    }
  return (res);
}

void is_ref_sequel(char **tab, int i)
{
  int nb;
  int k;

  nb = my_getdigit_until(&tab[i][38], '"');
  printf("----->");
  while (my_cmp_mod(tab[--i], "<reaction ") != 0);
  k = -1;
  while (my_cmp_mod(&tab[i][++k], "id=\"") != 0);
  k += 5;
  while (tab[i][k] != '"')
    {
      printf("%c", tab[i][k]);
      k += 1;
    }
  printf(" (%d)\n", nb);
}

void is_ref(char **tab, char *str)
{
  char c[100];
  int i;
  int k;

  inistr(c, 100);
  i = 0;
  printf("Liste of raactions consuming species %s (quantities)\n", str);
  sprintf(c, "species=\"%s\"", str);
  while (tab[i] != NULL)
    {
      k = 0;
      while (tab[i][k + 1] != '\0')
	{
	  if (my_cmp_mod(&tab[i][k], c) == 0)
	    break;
	  k += 1;
	}
      if (my_cmp_mod(&tab[i][k], c) == 0)
	is_ref_sequel(tab, i);
      i += 1;
    }
}

void is_nothing(char **tab)
{
  int i;
  int k;

  printf("Liste of species\n");
  i = 0;
  while (tab[i] != NULL)
    {
      k = -1;
      if (my_cmp_mod(tab[i], "<species compartment=") == 0)
	{
	  while (my_cmp_mod(&tab[i][++k], "name=\"") != 0);
	  k += 6;
	  printf("----->");
	  while (tab[i][k] != '"')
	    {
	      printf("%c", tab[i][k]);
	      k += 1;
	    }
	  printf("\n");
	}
      i += 1;
    }
}

void algo(char **tab, char *search, int arge)
{
  int i;

  i = what_is_it(tab, search);
  if (i == REFERENCE)
    is_ref(tab, search);
  else if (i == SPECIES)
    is_species(tab, search);
  else if (i == REACTION)
    is_reaction(tab, search, arge);
  else
    is_nothing(tab);
}

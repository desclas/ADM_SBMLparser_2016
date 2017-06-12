/*
** sort_file.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 18:54:54 2017 Mathias
** Last update Mon Jun 12 19:07:48 2017 Mathias
*/

#include "parser.h"

int my_cmp_mod(char *tab, char *str)
{
  int i;
  int count;

  i = 0;
  count = 0;
  if (tab[i] == '\t')
    while (tab[++i] == '\t');
  while (tab[i] != '\0' && str[count] != '\0')
    {
      if (tab[i] != str[count])
	return (1);
      i += 1;
      count += 1;
    }
  if (str[count] != '\0')
    return (1);
  return (0);
}

int check_name(char **tab, int i, int k)
{
  int ii;
  int ik;

  ii = 0;
  ik = 0;
  while (my_cmp_mod(&tab[i][ii], "name") != 0)
    ii += 1;
  while (my_cmp_mod(&tab[k][ik], "name") != 0)
    ik += 1;
  while (tab[i][ii] != '\0' && tab[k][ik] != '\0')
    {
      if (tab[i][ii] > tab[k][ik])
	return (1);
      if (tab[i][ii] < tab[k][ik])
	break;
      ii += 1;
      ik += 1;
    }
  return (0);
}

void sort_file_final(char **tab)
{
  int i;
  int k;
  int j;
  char *tmp;

  i = -1;
  while (tab[++i] != NULL)
    if (my_cmp_mod(tab[i], "<model name") == 0)
      {
	k = i;
	while (tab[++k] != NULL &&
	       my_cmp_mod(tab[k], "<model name") != 0);
	if (tab[k] != NULL && check_name(tab, i, k) == 1)
	  while (my_cmp_mod(tab[k], "</model>") != 0)
	    {
	      j = k + 1;
	      tmp = tab[k];
	      while (--j != i)
		tab[j] = tab[j - 1];
	      i += 1;
	      k += 1;
	    }
      }
}

void sort_file_sequel(char **tab)
{
  int i;
  int k;
  int j;
  char *tmp;

  i = -1;
  while (tab[++i] != NULL)
    if (my_cmp_mod(tab[i], "<reaction reversible") == 0)
      {
	k = i;
	while (tab[++k] != NULL &&
	       my_cmp_mod(tab[k], "<reaction reversible") != 0);
	if (tab[k] != NULL && check_name(tab, i, k) == 1)
	  while (my_cmp_mod(tab[k], "</reaction>") != 0)
	    {
	      j = k + 1;
	      tmp = tab[k];
	      while (--j != i)
		tab[j] = tab[j - 1];
	      i += 1;
	      k += 1;
	    }
      }
  sort_file_final(tab);
}

void sort_file(char **tab)
{
  int i;
  int k;

  i = -1;
  while (tab[++i] != NULL)
    if (my_cmp_mod(tab[i], "<listOfCompartments>") == 0 ||
	my_cmp_mod(tab[i], "<listOfSpecies>") == 0 ||
	my_cmp_mod(tab[i], "<listOfReactants>") == 0 ||
	my_cmp_mod(tab[i], "<listOfProducts>") == 0)
      {
	k = i;
	while (my_cmp_mod(tab[k], "</listOfCompartments>") != 0 &&
	       my_cmp_mod(tab[k], "</listOfSpecies>") != 0 &&
	       my_cmp_mod(tab[k], "</listOfReactants>") != 0 &&
	       my_cmp_mod(tab[k], "</listOfProducts>") != 0)
	  k += 1;
	sort_tab_until(tab, i + 1, k);
      }
  sort_file_sequel(tab);
}

/*
** is_reaction.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 19:02:17 2017 Mathias
** Last update Mon Jun 12 19:03:12 2017 Mathias
*/

#include "parser.h"

void is_reaction_equation_sequel(char **tab, int i, int *check)
{
  int k;

  if (*check == 1)
    write(1, " + ", 3);
  k = 38;
  while (tab[i][k] != '"')
    {
      write(1, &tab[i][k], 1);
      k += 1;
    }
  write(1, " ", 1);
  while (tab[i][++k] != '"');
  while (tab[i][++k] != '"')
    write(1, &tab[i][k], 1);
  *check = 1;
}

void is_reaction_equation(char **tab, int i)
{
  int rev;
  int k;
  int check;

  check = 0;
  if (my_cmp_mod(&tab[i][25], "false") == 0)
    rev = 0;
  else
    rev = 1;
  i += 2;
  while (my_cmp_mod(tab[i], "</listOfProducts>") != 0)
    {
      if (my_cmp_mod(tab[i], "<speciesReference stoichiometry=") == 0)
	is_reaction_equation_sequel(tab, i, &check);
      if (my_cmp_mod(tab[i], "</listOfReactants>") == 0)
	{
	  check = 0;
	  if (rev == 1)
	    write(1, " <-> ", 5);
	  else
	    write(1, " -> ", 4);
	}
      i += 1;
    }
  write(1, "\n", 1);
}

void is_reaction_sequel(char **tab, char *str, int i)
{
  int k;

  printf("List of reactants of reaction %s\n", str);
  i += 2;
  while (my_cmp_mod(tab[i], "</listOfProducts>") != 0)
    {
      if (my_cmp_mod(tab[i], "<speciesReference stoichiometry") == 0)
	{
	  k = 0;
	  while (my_cmp_mod(&tab[i][++k], "species=\"") != 0);
	  write(1, "----->", 6);
	  k += 8;
	  while (tab[i][++k] != '"')
	    write(1, &tab[i][k], 1);
	  write(1, "\n", 1);
	}
      if (my_cmp_mod(tab[i], "<listOfProducts>") == 0)
	printf("List of products of reaction %s\n", str);
      i += 1;
    }
}

void is_reaction(char **tab, char *search, int arge)
{
  char c[100];
  int i;
  int k;

  inistr(c, 100);
  sprintf(c, "id=\"%s\"", search);
  i = 0;
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
	break;
      i += 1;
    }
  if (arge == 1)
    is_reaction_equation(tab, i);
  else
    is_reaction_sequel(tab, search, i);
}
/*
** part_disp.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 18:58:19 2017 Mathias
** Last update Tue Jun 13 11:18:55 2017 mathias descoins
*/

#include "parser.h"

void sort_tab_until(char **tab, int begin, int end)
{
  int i;
  int k;
  char *tmp;

  i = begin - 1;
  while (++i != end)
    if (i + 1 != end && (k = 0) == 0)
      {
	while (tab[i][k] != '\0' && tab[i + 1][k] != '\0')
	  {
	    if (tab[i][k] > tab[i + 1][k])
	      break;
	    else if (tab[i][k] < tab[i + 1][k])
	      break;
	    k += 1;
	  }
	if (tab[i][k] > tab[i + 1][k])
	  {
	    tmp = tab[i];
	    tab[i] = tab[i + 1];
	    tab[i + 1] = tmp;
	    i = begin - 1;
	  }
      }
}

int help(char *name)
{
  printf("USAGE\n\t%s SBMLfile [-i ID [-e]] [-json]\n\nDESCRIPTION\n", name);
  printf("\tSBMLfileSMBL file\n\t-i ID\tid of compartment, reaction or ");
  printf("product to be extracted (ignored if uncorrect)\n\t-e\tprint");
  printf(" the equation if a reaction ID is given as argument ");
  printf("(ignored otherwise)\n\t-json\ttransform the file into a JSON");
  printf(" file\n");
  return (0);
}

void disp_auto(void)
{
  printf("compartment\n----->id\n----->name\nmodel\n----->id\n----->name\n");
  printf("reaction\n----->id\n----->name\n----->reversible\nsbml\n");
  printf("----->level\n----->version\n----->xmlns\nspecies\n");
  printf("----->compartment\n----->id\n----->name\nspeciesReference\n");
  printf("----->species\n----->stoichiometry\n");
}

int what_is_it(char **tab, char *str)
{
  int i;
  int k;

  i = -1;
  while (tab[++i] != NULL)
    {
      k = -1;
      while (tab[i][++k] != '\0')
	if (my_cmp_mod(&tab[i][k], str) == 0)
	  break;
      if (my_cmp_mod(&tab[i][k], str) == 0)
	{
	  while (tab[i][--k] != '=');
	  while (tab[i][--k] != ' ');
	  k += 1;
	  if (my_cmp_mod(&tab[i][k], "id") == 0 &&
	      my_cmp_mod(tab[i], "<reaction ") == 0)
	    return (REACTION);
	  else if (my_cmp_mod(&tab[i][k], "species") == 0)
	    return (REFERENCE);
	  else if (my_cmp_mod(&tab[i][k], "compartment") == 0)
	    return (SPECIES);
	}
    }
  return (FAIL);
}

void is_species(char **tab, char *str)
{
  char c[100];
  int i;
  int k;

  inistr(c, 100);
  sprintf(c, "compartment=\"%s\"", str);
  printf("Liste of species in compartment %s\n", str);
  i = 0;
  while (tab[i] != NULL)
    {
      k = -1;
      if (check_line(tab[i], c) == 0)
	{
	  while (my_cmp_mod(&tab[i][++k], "name=\"") != 0);
	  k += 7;
	  write(1, "----->", 6);
	  while (tab[i][k] != '"')
	    {
	      write(1, &tab[i][k], 1);
	      k += 1;
	    }
	  write(1, "\n", 1);
	}
      i += 1;
    }
}

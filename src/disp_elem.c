/*
** disp_elem.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016/src
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Jun 13 15:51:58 2017 Mathias
** Last update Tue Jun 13 15:57:14 2017 Mathias
*/

#include "parser.h"

void erase_double(t_elem **elem)
{
  int i;
  int k;

  i = 0;
  while (elem[i] != NULL)
    {
      if (elem[i + 1] != NULL &&
	  my_cmp_mod(elem[i]->name, elem[i + 1]->name) == 0)
	{
	  k = -1;
	  free(elem[i]->name);
	  while (elem[i]->part[++k] != NULL)
	    free(elem[i]->part[k]);
	  free(elem[i]->part);
	  free(elem[i]);
	  while (elem[i] != NULL)
	    {
	      elem[i] = elem[i + 1];
	      i += 1;
	    }
	  i = -1;
	}
      i += 1;
    }
}

void disp_it(t_elem **elem)
{
  int i;
  int k;

  i = 0;
  erase_double(elem);
  while (elem[i] != NULL)
    {
      k = 0;
      printf("%s\n", elem[i]->name);
      free(elem[i]->name);
      while (elem[i]->part[k] != NULL)
	{
	  printf("----->%s\n", elem[i]->part[k]);
	  free(elem[i]->part[k]);
	  k += 1;
	}
      free(elem[i]->part);
      free(elem[i]);
      i += 1;
    }
  free(elem);
}

void disp_elem_sequel(t_elem **elem)
{
  int i;
  int k;

  i = 0;
  while (elem[i] != NULL)
    {
      k = -1;
      while (elem[i]->part[++k] != NULL);
      sort_tab_until(elem[i]->part, 0, k);
      i += 1;
    }
  disp_it(elem);
}

void disp_elem(t_elem **elem)
{
  int i;
  t_elem *tmp;
  int k;

  i = -1;
  while (elem[++i] != NULL)
    if (elem[i + 1] != NULL)
      {
	k = -1;
	while (elem[i]->name[++k] != '\0' && elem[i + 1]->name[k] != '\0')
	  if (elem[i]->name[k] < elem[i + 1]->name[k])
	    break;
	  else if (elem[i]->name[k] > elem[i + 1]->name[k])
	    break;
	if (elem[i]->name[k] > elem[i + 1]->name[k])
	  {
	    tmp = elem[i];
	    elem[i] = elem[i + 1];
	    elem[i + 1] = tmp;
	    i = -1;
	  }
      }
  disp_elem_sequel(elem);
}

void disp_auto(char **tab)
{
  t_elem **elem;
  int i;
  int count;

  i = 0;
  count = 0;
  elem = malloc(sizeof(t_elem *));
  elem[0] = NULL;
  while (tab[++i] != NULL)
    if (my_cmp_mod(tab[i], "</") != 0)
      add_elem((elem = append_elem(elem)) , tab[i], &count);
  disp_elem(elem);
}

/*
** add_ele.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016/src
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Tue Jun 13 15:53:55 2017 Mathias
** Last update Wed Jun 14 16:35:14 2017 Mathias
*/

#include "parser.h"

t_elem **append_elem(t_elem **elem)
{
  int i;
  t_elem **res;

  i = -1;
  while (elem[++i] != NULL);
  res = malloc(sizeof(t_elem *) * (i + 2));
  i = 0;
  while (elem[i] != NULL)
    {
      res[i] = elem[i];
      i += 1;
    }
  res[i] = malloc(sizeof(t_elem));
  res[i + 1] = NULL;
  free(elem);
  return (res);
}

void add_elem_sequel(t_elem **elem, char *str, int count)
{
  int i;
  char *res;

  i = 0;
  res = malloc(sizeof(char));
  res[0] = '\0';
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	{
	  while (str[--i] != ' ' && str[i] != '\t');
	  while (str[++i] != '=')
	    res = append_char(res, str[i]);
	  elem[count - 1]->part = append_chartab(elem[count - 1]->part, res);
	  res = malloc(sizeof(char));
	  res[0] = '\0';
	}
      i += 1;
    }
  free(res);
}

void add_elem(t_elem **elem, char *str, int *count)
{
  int i;
  char *res;

  i = -1;
  res = malloc(sizeof(char));
  res[0] = '\0';
  while (str[++i] != '\0' && str[i] != ' ');
  if (str[i] != '\0')
    {
      *count += 1;
      i = -1;
      while (str[++i] != '<');
      while (str[i] != '\0' && str[++i] != ' ' && str[i] != '\t')
	res = append_char(res, str[i]);
      elem[*count - 1]->name = res;
      elem[*count - 1]->part = malloc(sizeof(char *));
      elem[*count - 1]->part[0] = NULL;
      add_elem_sequel(elem, str, *count);
    }
  else
    {
      free(elem[*count]);
      elem[*count] = NULL;
      free(res);
    }
}

char *have_reaction(char *tab)
{
  int i;
  char *str;

  i = 0;
  str = malloc(sizeof(char));
  str[0] = '\0';
  while (my_cmp_mod(&tab[++i], "id=\"") != 0);
  i += 5;
  while (tab[i] != '"')
    {
      str = append_char(str, tab[i]);
      i += 1;
    }
  return (str);
}

int safe(char *str)
{
  int i;

  i = -1;
  while (str[++i] != '\0' && str[i] != '<');
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	return (0);
      i += 1;
    }
  return (1);
}

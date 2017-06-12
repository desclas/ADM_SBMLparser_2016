/*
** gnl.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_SBMLparser_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 12 18:51:58 2017 Mathias
** Last update Mon Jun 12 18:52:27 2017 Mathias
*/

#include "parser.h"

int my_len(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

void inistr(char *str, int max)
{
  int i;

  i = 0;
  while (i != max)
    {
      str[i] = '\0';
      i += 1;
    }
}

char *append_char(char *str, char c)
{
  char *res;
  int i;

  i = 0;
  res = malloc(sizeof(char) * (my_len(str) + 2));
  inistr(res, my_len(str) + 2);
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = c;
  free(str);
  return (res);
}

char **append_chartab(char **tab, char *str)
{
  char **res;
  int i;

  i = -1;
  while (tab[++i] != NULL);
  res = malloc(sizeof(char *) * (i + 2));
  i = 0;
  while (tab[i] != NULL)
    {
      res[i] = tab[i];
      i += 1;
    }
  res[i] = str;
  res[i + 1] = NULL;
  free(tab);
  return (res);
}

char *my_gnl(int fd)
{
  char *str;
  char c;
  int k;
  
  str = malloc(sizeof(char));
  str[0] = '\0';
  c = '\0';
  while (1)
    {
      k = read(fd, &c, 1);
      if (!(c >= 0) || c == '\0' || c == '\n' || k < 1)
	break;
      str = append_char(str, c);
    }
  if (str[0] == '\0' || c < 0)
    {
      free(str);
      return (NULL);
    }
  return (str);
}

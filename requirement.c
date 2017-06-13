#include <stdlib.h>

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

char *append_char(char *str, char c)
{
  char *res;
  int i;

  i = -1;
  while (str[++i] != '\0');
  res = malloc(sizeof(char) * (i + 2));
  inistr(res, i + 2);
  i = 0;
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = c;
  free(str);
  return (res);
}

int is_alphanum(char c)
{
  if (!(c <= 58 && c >= 47) && !(c <= 122 && c >= 97) && !(c <= 90 && c >= 65)
      && c != '\0')
    return (1);
  return (0);
}

char **my_strtowordtab_synthesis(char const *str)
{
  char **tab;
  char *res;
  int i;

  i = 0;
  tab = malloc(sizeof(char *));
  res = malloc(sizeof(char));
  res[0] = '\0';
  tab[0] = NULL;
  while (str[i] != '\0')
    {
      if (is_alphanum(str[i]) == 0)
	res = append_char(res, str[i]);
      else
	{
	  while (is_alphanum(str[++i]) != 0);
	  i -= 1;
	  tab = append_chartab(tab, res);
	  res = malloc(sizeof(char));
	  res[0] = '\0';
	}
      i += 1;
    }
  tab = append_chartab(tab, res);
  return (tab);
}

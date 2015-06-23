/*
** my_strncmp.c for my_strncmp in /home/rieux-_t/rendu/Piscine_C_J07/lib/my
** 
** Made by Thomas Rieux-Laucat
** Login   <rieux-_t@epitech.net>
** 
** Started on  Wed Oct  8 15:46:05 2014 Thomas Rieux-Laucat
** Last update Tue Nov  4 15:04:03 2014 thomas rieux-laucat
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && i < nb)
    i++;
  return (s1[i] - s2[i]);
}

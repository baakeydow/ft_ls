/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:24:05 by bndao             #+#    #+#             */
/*   Updated: 2016/03/17 07:24:32 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int print_dir(int all, int ac, char **av)
{
  DIR     *dir = NULL;
  struct  dirent *file = NULL;
  int     i;

  i = 1;
  if (all == 0 && ac == 1)
    if ((dir = opendir("./")))
      while ((file = readdir(dir)))
        if (file->d_name[0] != '.')
          ft_putendl(file->d_name);
  if (all == 0 && ac != 1)
    while (av[i])
    {
      if ((dir = opendir(av[i])))
      {
        while ((file = readdir(dir)))
          if (file->d_name[0] != '.')
            ft_putendl(file->d_name);
      }
      ft_putendl(av[i]);
      i++;
    }
  if (closedir(dir) == -1)
  {
    perror("Error ");
    return(EXIT_FAILURE);
  }
  return (1);
}

int     main(int ac, char **av)
{
  print_dir(0, ac, av);
  return (0);
}

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

int print_current_dir(int ac)
{
  DIR *dir = NULL;
  struct dirent *file = NULL;

  if (ac == 1)
    if ((dir = opendir("./")))
    {
      while ((file = readdir(dir)))
      {
        if (file->d_name[0] != '.')
          ft_putendl(file->d_name);
      }
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
  ft_putstr("This is a test for the program ");
  ft_putendl(av[0]);
  if (ac == 1)
    print_current_dir(ac);
  return (0);
}

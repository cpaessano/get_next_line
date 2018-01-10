/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:59:53 by csilva            #+#    #+#             */
/*   Updated: 2017/12/12 13:19:59 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

#include <stdio.h>

int	store_txt(int fd, char **arr, int ret)
{
	char *tmp;

	if (!(tmp = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (!arr[fd])
			arr[fd] = ft_strdup(tmp);
		else
			arr[fd] = ft_strjoin(arr[fd], tmp);
	}
	free(tmp);
	if (ret < 0)
		return (-1);
	return (0);
}

int	ft_count(char *arr)
{
	int i;

	i = 0;
	while (arr[i] != '\n' && arr[i] != '\0')
		i++;
	return (i);
}

int	copy_line(char **arr, char **line)
{
	int i;
	int j;

	i = 0;
	if (!(*arr) || !(*arr)[i])
		return (0);
	while ((*arr)[i] != '\n' && (*arr)[i] != '\0')
	{
		(*line)[i] = (*arr)[i];
		i++;
	}
	(*line)[i] = '\0';
	if ((*arr)[i] == '\n')
		i++;
	j = 0;
	while ((*arr)[i])
	{
		(*arr)[j++] = (*arr)[i];
		(*arr)[i++] = '\0';
	}
	(*arr)[j] = '\0';
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *arr[4867];
	int			res;

	if (!line || fd < 0 || fd > 4867)
		return (-1);
	if ((res = store_txt(fd, arr, 0)) == -1)
		return (-1);
	if (!arr[fd])
		return (0);
	*line = ft_strnew(ft_count(arr[fd]));
	if (!(copy_line(&arr[fd], line)))
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	int fd;
	char *line;

	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
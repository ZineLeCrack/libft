/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:33:20 by rlebaill          #+#    #+#             */
/*   Updated: 2024/10/24 11:26:32 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd)
{
	char	*buf;
	char	*new_buf;
	char	*tmp;
	ssize_t	bytes_read;

	buf = NULL;
	tmp = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!tmp)
		return (NULL);
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	while (bytes_read)
	{
		if (bytes_read < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		new_buf = ft_strjoin(buf, tmp);
		free(buf);
		buf = new_buf;
		bytes_read = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (buf);
}

static char	*get_line(int i, char *buf)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (buf)
	{
		while (buf[j])
		{
			if (k == i)
				return (ft_end(&buf[j], '\n'));
			if (buf[j] == '\n')
				k++;
			j++;
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*next_line;
	static int	i = 0;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buf)
		buf = read_file(fd);
	next_line = get_line(i, buf);
	if (!next_line)
		return (NULL);
	i++;
	return (next_line);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;
	char	*next_line;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i < 13)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		free(next_line);
		i++;
	}
	return (0);
}*/

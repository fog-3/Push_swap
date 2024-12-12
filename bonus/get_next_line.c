/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:02:43 by fernando          #+#    #+#             */
/*   Updated: 2024/12/12 10:03:05 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*join_free(char *str, char buffer)
{
	char	*aux;
	int		len;

	len = 0;
	if (str)
		len = ft_strlen(str);
	aux = (char *)malloc((len + 2) * sizeof(char));
	if (!aux)
		return (0);
	len = 0;
	if (str)
	{
		while (str[len])
		{
			aux[len] = str[len];
			len++;
		}
	}
	aux[len] = buffer;
	aux[len + 1] = '\0';
	free(str);
	str = NULL;
	return (aux);
}

char	*ft_readline(int fd, char *line)
{
	char	buffer;
	int		bufn;

	bufn = 1;
	buffer = '\0';
	while (bufn > 0 && buffer != '\n')
	{
		bufn = read(fd, &buffer, 1);
		if (bufn < 0)
		{
			free(line);
			line = NULL;
			return (0);
		}
		line = join_free(line, buffer);
		if (!line)
			return (0);
	}
	if (bufn <= 0 || ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd, t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	if (read(fd, 0, 0) < 0)
		clean_exit(a, b, 0, "Error: the file does not exist\n");
	line = ft_readline(fd, line);
	if (!line)
		return (0);
	return (line);
}

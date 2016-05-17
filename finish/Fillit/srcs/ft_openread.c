/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:01:40 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/21 17:58:14 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_openread(char *name)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = 0;
	str = (char*)malloc(sizeof(str) * ret + 1);
	if (str)
		str = ft_strcpy(str, buf);
	return (str);
}

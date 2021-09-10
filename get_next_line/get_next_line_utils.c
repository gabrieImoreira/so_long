/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:54:10 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/10 18:47:10 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove_gnl(void *dest, const void *src, size_t len)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (ptr_dest > ptr_src)
		while (len-- > 0)
			ptr_dest[len] = ptr_src[len];
	else
	{
		while (i < len)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}

int	ft_is_new_line(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len;
	char	*repo;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen_gnl((char *)s1) + ft_strlen_gnl((char *)s2) + 1;
	repo = malloc(sizeof(char) * len);
	if (!repo)
		return (0);
	ft_memmove_gnl(repo, s1, ft_strlen_gnl((char *)s1));
	ft_memmove_gnl(repo + ft_strlen_gnl((char *)s1), s2,
		ft_strlen_gnl((char *)s2));
	repo[len - 1] = '\0';
	free((char *)s1);
	return (repo);
}

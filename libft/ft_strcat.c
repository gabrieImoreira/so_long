/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:49:09 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/09 23:55:27 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t			len;
	size_t			i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = 0;
	return (dest);
}

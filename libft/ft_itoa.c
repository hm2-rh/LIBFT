/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:13:25 by hrhirha           #+#    #+#             */
/*   Updated: 2019/10/29 09:39:56 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_malloc_len(int i)
{
	unsigned int	ui;
	int				len;

	len = 0;
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	ui = i;
	if (ui == 0)
		len++;
	if (ui > 0)
	{
		while (ui != 0)
		{
			ui /= 10;
			len++;
		}
	}
	return (len);
}

static	int		ft_isnegative(int i, char *str)
{
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	return (i);
}

char			*ft_itoa(int i)
{
	unsigned int	ui;
	int				count;
	char			*digits;
	char			*str;

	count = ft_malloc_len(i);
	digits = "0123456789";
	if (!(str = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	ui = ft_isnegative(i, str);
	str[count--] = '\0';
	if (ui == 0)
		str[count] = digits[0];
	if (ui > 0)
	{
		while (count >= 0 && ui != 0)
		{
			str[count] = digits[ui % 10];
			count--;
			ui /= 10;
		}
	}
	return (str);
}

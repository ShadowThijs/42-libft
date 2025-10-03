/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:09:27 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/09/02 18:09:27 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;
	long long	temp;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	temp = nbr % 10 + '0';
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		write(fd, &temp, 1);
	}
	else
		write(fd, &temp, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:05:41 by sshawnta          #+#    #+#             */
/*   Updated: 2019/07/24 19:24:04 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(const char *str)
{
	if (str == ERR_NO_NUMBERS)
		exit(1);
	ft_putendl("Error");
	exit(1);
}

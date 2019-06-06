/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <sshawnta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:53:39 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/11 16:54:51 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# define MAX_FD 1024 + 1

# include "libft/libft.h"

int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_next_line(const int fd, char **line);
#endif

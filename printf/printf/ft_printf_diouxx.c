/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diouxx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:04:45 by sshawnta          #+#    #+#             */
/*   Updated: 2019/05/28 15:04:48 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_di(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_itoabase(base, va_arg(*args, int));
	return (1);
}

int		ft_printf_o(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_uitoabase(base, va_arg(*args, UI));
	return (1);
}

int		ft_printf_u(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_uitoabase(base, va_arg(*args, UI));
	return (1);
}

int		ft_printf_x(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_uitoabase(base, va_arg(*args, UI));
	return (1);
}

int		ft_printf_cap_x(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_uitoabase(base, va_arg(*args, UI));
	return (1);
}

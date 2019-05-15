#include "ft_printf.h"

inline extern int			is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

inline extern int			is_it_modifier(const char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

inline extern int			is_it_flag(const char c)
{
	return (ft_strchr("#0-+' ", c) != NULL);
}

inline extern int			is_precision(const char c)
{
	return (ft_strchr("$*.1234567890", c) != NULL);
}

int					is_valid(const char c)
{
	return (is_conversion(c) || is_it_modifier(c) || is_it_flag(c) || is_precision(c));
}
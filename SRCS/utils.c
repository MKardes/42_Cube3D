#include "../INC/cube.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	if (ft_strstr(ERR_MAP, str))
		return (MAP_RET);
	return (0);
}
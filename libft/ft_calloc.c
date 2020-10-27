#include "libft.h"

void	*ft_calloc(size_t data_ammout, size_t size)
{
	char *new;

	if (!(new = malloc(data_ammout * size)))
		return (NULL);
	ft_memset(new, 0, data_ammout * size);
	return (new);
}

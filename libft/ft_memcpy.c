#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	i = -1;
	while (++i < n)
	{
		*ptr = *(unsigned char *)src;
		ptr++;
		src++;
	}
	return (dst);
}

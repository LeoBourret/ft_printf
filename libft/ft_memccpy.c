#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*ptr_s;
	char	*ptr_d;

	ptr_s = (char *)src;
	ptr_d = (char *)dest;
	i = -1;
	while (++i < n && ptr_s[i] != c)
		ptr_d[i] = ptr_s[i];
	if (i == n)
		return (NULL);
	ptr_d[i] = ptr_s[i];
	return (&ptr_d[i + 1]);
}

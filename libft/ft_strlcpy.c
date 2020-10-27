#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len_src;
	size_t i;

	len_src = ft_strlen(src);
	if (size <= 0)
		return (len_src);
	i = -1;
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (len_src);
}

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = -1;
	if (!s2)
		return ((char*)s1);
	while (s1[++i] && i < len)
	{
		j = 0;
		while (j + i < len && s1[j + i] == s2[j])
			j++;
		if (s2[j] == 0)
			return ((char*)&s1[i]);
	}
	return (NULL);
}

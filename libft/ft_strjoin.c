#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1));
	ft_strlcat(new, s2, len);
	return (new);
}

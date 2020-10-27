#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(s);
	if (!(new = malloc(sizeof(char*) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}

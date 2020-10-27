#include "libft.h"

int		is_charset(char c, char charset)
{
	if (c == charset)
			return (1);
	return (0);
}

int		ft_strlen_split(char const *str, char charset)
{
	int i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	return (i);
}

char	*ft_strdup_split(char const *str, char charset)
{
	int		i;
	int		size;
	char	*new_str;

	size = ft_strlen_split(str, charset);
	new_str = malloc(sizeof(char *) * size + 1);
	i = -1;
	while (++i < size)
		new_str[i] = str[i];
	return (new_str);
}

int		how_many_words(char const *str, char charset)
{
	int words;
	int i;

	i = -1;
	words = 0;
	while (str[++i])
		if (!is_charset(str[i], charset)
		&& (is_charset(str[i + 1], charset) || str[i + 1] == '\0'))
			words++;
return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_number;
	int		i;
	int		j;

	if (s == 0 || c == 0)
		return (NULL);
	words_number = how_many_words(s, c);
	if (!(res = malloc(sizeof(char *) * words_number + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < words_number)
	{
		while (is_charset(s[j], c) && s[j])
			j++;
		res[i] = ft_strdup_split(&s[j], c);
		while (!is_charset(s[j], c) && s[j])
			j++;
	}
	res[i] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <lebourre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:23:30 by lebourre          #+#    #+#             */
/*   Updated: 2020/11/22 15:12:08 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**del_if_malloc_error(char **split)
{
	int i;

	i = -1;
	while (split[++i])
		if (split[i] != NULL)
		{
			free(split[i]);
			split[i] = NULL;
		}
	free(split);
	split = NULL;
	return (NULL);
}

static int		ft_strlen_split(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int		how_many_words(char *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = -1;
	while (str[++i])
		if (str[i] != c
		&& ((str[i + 1] == c) || str[i + 1] == '\0'))
			words++;
	return (words);
}

static char		*ft_strdup_split(char *str, char c)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(char) * ft_strlen_split(str, c) + 1)))
		return (NULL);
	i = 0;
	while (str[i] && (str[i] != c))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**ret;

	i = 0;
	j = -1;
	words = how_many_words((char *)str, c);
	if (!str)
		return (NULL);
	if (!(ret = malloc(sizeof(char *) * (words + 1))))
		return (0);
	ret[words] = NULL;
	while (++j < words)
	{
		while ((str[i] == c) && str[i])
			i++;
		if (!(ret[j] = ft_strdup_split((char *)&str[i], c)))
			return (del_if_malloc_error(ret));
		while ((str[i] != c) && str[i])
			i++;
	}
	return (ret);
}

#include <stdlib.h>
#include <errno.h>
#include "ft_str.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*dst;
	int		i;

	len = ft_strlen(src);
	dst = (char *) malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst == NULL)
		errno = ENOMEM;
	return (dst);
}

char	*ft_strndup(char *src, int pos, int size)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(*dest) * (size + 1))))
		return (0);
	while (i < size)
	{
		dest[i] = src[pos + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_is_charset(char *src, int pos, char *charset)
{
	int i;

	i = 0;
	while (i < ft_strlen(charset))
	{
		if (src[pos] == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_wrdlen(char *str, int pos, char *charset)
{
	int i;

	i = 0;
	while (str[pos + i] != '\0' && ft_is_charset(str, (pos + i), charset) == 1)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		line;
	int		size;

	line = 0;
	i = 0;
	if (!(split = malloc(sizeof(*split) * (ft_strlen(str) + 1))))
		return (0);
	while (i < ft_strlen(str))
	{
		if (ft_is_charset(str, i, charset) == 1)
		{
			size = ft_wrdlen(str, i, charset);
			split[line] = ft_strndup(str, i, size);
			i = i + size;
			line = line + 1;
		}
		i++;
	}
	split[line] = 0;
	return (split);
}

void	ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
}

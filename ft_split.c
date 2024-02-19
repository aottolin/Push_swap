#include "libpushswap.h"

static int	count_words(char *s, char c)
{
	int	contador;
	int warn;

	contador = 0;
	warn = 0;
	while (*s)
	{
		if (*s != c && warn == 0)
		{
			contador++;
			warn = 1;
		}
		else if (*s == c)
			warn = 0;
		s++;
	}
	return (contador);
}

static int	len_words(char *st, char ch)
{
	int contador;

	contador = 0;
	while (*st == ch)
		st++;
	while (*st != ch)
	{
		contador++;
		st++;
	}
	return (contador);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	x;

	x = 0;
	if (size != 0)
	{
		while (src[x] && x < size - 1)
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char *s, int start, int len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s + start, len + 1);
	return (cpy);
}

static char	**free_m(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		--i;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char *str, char delim)
{
	char	**array;
	int		j;
	int		i;

	array = (char **)malloc(sizeof(char *) * (count_words(str, delim) + 1));
	if (!array)
		return (NULL);
	j = 0;
	i = 0;
	while (i < count_words(str, delim))
	{
		while (str[j] == delim && str[j])
			j++;
		array[i] = ft_substr(str, j, len_words(&str[j], delim));
		if (!array[i])
			return (free_m(array, i));
		j += len_words(&str[j], delim);
		i++;
	}
	array[i] = 0;
	return (array);
}

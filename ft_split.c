#include "libft.h"

static size_t	ft_numofsplit(char const *s, char c)
{
	long long	pre;
	long long	now;
	size_t		counter;

	now = 0;
	pre = -2;
	counter = 0;
	while (s[now] != '\0')
	{
		if (s[now] != c)
		{
			if (now > 1 + pre)
				counter++;
			pre = now;
		}
		now++;
	}
	return (counter);
}

static int	mallofree(char **dst, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (1);
}

static char	*makesentense(char **dst, char *front, char c, size_t i)
{
	char	*end;

	while (*front == c && *front != '\0')
		front++;
	end = front;
	while (*end != c && *front != '\0' && *end != '\0')
		end++;
	dst[i] = malloc(sizeof(char) * (end - front + 1));
	if (dst[i] == NULL && mallofree(dst, i))
		return (NULL);
	ft_strlcpy(dst[i], front, end - front + 1);
	front = end;
	i++;
	return (front);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*front;
	char	**dst;

	if (!s)
		return (NULL);
	i = 0;
	dst = malloc(sizeof(char *) * (ft_numofsplit(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	front = (char *)s;
	while (i < ft_numofsplit(s, c))
	{
		front = makesentense(dst, front, c, i);//front c i dst
		if (front == NULL)
			return (NULL);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

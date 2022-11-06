#include "libft.h"

static size_t    ft_numofsplit(char const *s, char c)
{
    long long    pre;
    long long    now;
    size_t        counter;

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

static int    mallofree(char **dst, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        free(dst[i]);
        i++;
    }
    free(dst);
    return (1);
}

static char    *makesentense(char **dst, char *front, char c, size_t i)
{
    char    *end;

    while (*front == c && *front != '\0')                //aaaapppppppaappap
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

char    **ft_split(char const *s, char c)
{
    size_t    i;
    char    *front;
    char    **dst;

    if (!s)
        return (NULL);
    i = 0;
    dst = malloc(sizeof(char *) * (ft_numofsplit(s, c) + 1));
    if (dst == NULL)
        return (NULL);
    front = (char *)s;
	// ここまで
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

int	main(void)
{
	// char	str[20] = "aa b    cc d ";
	char	**return_value_str;

	char	*str="\0aa\0bbb";
	// char	*str = "aa bb cc dd";
	size_t	return_value;
	size_t	number;

	// return_value = counter(str, '\0');
	// printf("%zu\n", return_value);
	// printf("元の文字列：%s\n", string);
	// number = strlen(str);
	// printf("元の文字列の文字数：%zu\n", number);
	return_value_str = ft_split(str, '\0');
	for (size_t i = 0; i < 2; i++)
		printf("%s\n", return_value_str[i]);
}

#include "libft.h"

char	**allocate(char const *s, char c, int flag, int position_s, char **re_value);
char	*makeptr(char *s);
void	*free_memory(char **return_value, int i);
void	deli_null(char *nc_s, char c);
size_t	counter(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		position_s;
	int		flag;
	char	**return_value;

	if (!s)
		return (NULL);
	return_value = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!return_value)
		return (NULL);
	flag = 0;
	position_s = 0;
	return (allocate(s, c, flag, position_s, return_value));
}

char	**allocate(char const *s, char c, int flag, int position_s, char **re_value)
{
	size_t	number_s;
	int		i;
	char	*nc_s;

	nc_s = makeptr((char *)s);
	number_s = ft_strlen(nc_s);
	deli_null(nc_s, c);
	while (number_s--)
	{
		if (*(nc_s + position_s) == '\0')
			flag = 0;
		else if (*(nc_s + position_s) != '\0' && flag == 0)
		{
			re_value[i] = ft_strdup((const char *)(nc_s + position_s));
			if (!re_value[i])
				return (free_memory(re_value, i));
			i++;
			flag = 1;
		}
		// printf("%s\n", re_value[i]);
		position_s++;
	}
	re_value[i] = NULL;
	return (re_value);
}

char	*makeptr(char *s)
{
	char	*return_ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	return_ptr = malloc(len + 1);
	while (i < len)
	{
		return_ptr[i] = s[i];
		i++;
	}
	return_ptr[i] = '\0';
	return (return_ptr);
}

// 区切り文字をヌル文字に置き換える
void	deli_null(char *nc_s, char c)
{
	while (*nc_s)
	{
		if (*nc_s == c)
			*nc_s = '\0';
		nc_s++;
	}
}

// 単語がいくつあるかをカウント
// 単語の先頭にきたらflagを1にし単語数をカウント、flagの1の時は区切り文字でなくても条件を満たさない. 区切り文字にきたらflagを0にする
// size_tをintのどっちを使った方がいいのか
size_t	counter(char const *s, char c)
{
	size_t	word_count;
	int		position_s;
	int		flag;

	flag = 0;
	position_s = 0;
	word_count = 0;
	while (*(s + position_s))
	{
		if (*(s + position_s) == c)
			flag = 0;
		else if (*(s + position_s) != c && flag == 0)
		{
			word_count++;
			flag = 1;
		}
		position_s++;
	}
	return (word_count);
}

// メモリ解放
void	*free_memory(char **return_value, int i)
{
	while (i > 0)
		free(return_value[i--]);
	free(return_value);
	return (NULL);
}

int	main(void)
{
	// char	str[20] = "aa b    cc d ";
	char	**return_value_str;

	// char	*str="\0aa\0bbb";
	char	*str = "aa bb cc dd";
	size_t	return_value;
	size_t	number;

	// return_value = counter(str, '\0');
	// printf("%zu\n", return_value);
	// printf("元の文字列：%s\n", string);
	// number = strlen(str);
	// printf("元の文字列の文字数：%zu\n", number);
	return_value_str = ft_split(str, ' ');
	for (size_t i = 0; i <= 3; i++)
		printf("%s\n", return_value_str[i]);

}
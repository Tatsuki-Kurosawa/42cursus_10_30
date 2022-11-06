// #include "libft.h"

// size_t	counter(char const *s, char c);
// int		free_memory(char **dst, size_t n);
// char	*makesentense(char **dst, char *front, char c, size_t i);

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	char	*front;
// 	char	**dst;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	dst = malloc(sizeof(char *) * (counter(s, c) + 1));
// 	if (dst == NULL)
// 		return (NULL);
// 	front = (char *)s;
// 	while (i < counter(s, c))
// 	{
// 		front = makesentense(dst, front, c, i);
// 		if (front == NULL)
// 			return (NULL);
// 		i++;
// 	}
// 	dst[i] = NULL;
// 	return (dst);
// }

// size_t	counter(char const *s, char c)
// {
// 	size_t	word_count;
// 	int		position_s;
// 	int		flag;

// 	flag = 0;
// 	position_s = 0;
// 	word_count = 0;
// 	while (*(s + position_s))
// 	{
// 		if (*(s + position_s) == c)
// 			flag = 0;
// 		else if (*(s + position_s) != c && flag == 0)
// 		{
// 			word_count++;
// 			flag = 1;
// 		}
// 		position_s++;
// 	}
// 	return (word_count);
// }

// int	free_memory(char **dst, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		free(dst[i]);
// 		i++;
// 	}
// 	free(dst);
// 	return (1);
// }

// char	*makesentense(char **dst, char *front, char c, size_t i)
// {
// 	char	*end;

// 	while (*front == c && *front != '\0')
// 		front++;
// 	end = front;
// 	while (*end != c && *front != '\0' && *end != '\0')
// 		end++;
// 	dst[i] = malloc(sizeof(char) * (end - front + 1));
// 	if (dst[i] == NULL && free_memory(dst, i))
// 		return (NULL);
// 	ft_strlcpy(dst[i], front, end - front + 1);
// 	front = end;
// 	i++;
// 	return (front);
// }


// int	main(void)
// {
// 	// char	str[20] = "aa b    cc d ";
// 	char	**return_value_str;

// 	char	*str="\0aa\0bbb";
// 	// char	string[20] = "aa bb cc dd";
// 	size_t	number;

// 	// printf("%zu\n", return_value);
// 	// printf("元の文字列：%s\n", string);
// 	number = strlen(str);
// 	// printf("元の文字列の文字数：%zu\n", number);
// 	return_value_str = ft_split(str, '\0');
// 	for (size_t i = 0; i <= 5; i++)
// 		printf("%s\n", return_value_str[i]);
// }

// #include "libft.h"

// void	*free_memory(char **return_value, int i);
// void	deli_null(char *nc_s, char c);
// size_t	counter(char const *s, char c);

// char	**ft_split(char const *s, char c)
// {
// 	int		position_s;
// 	int		flag;
// 	int		i;
// 	char	**return_value;
// 	char	*nc_s;
// 	size_t	number_s;

// 	nc_s = (char *)s;
// 	while (*(nc_s) == c)
// 		nc_s++;
// 	number_s = ft_strlen(nc_s);
// 	return_value = malloc(sizeof(char *) * (counter(s, c) + 1));
// 	if (!return_value)
// 		return (NULL);
// 	deli_null(nc_s, c);
// 	position_s = 0;
// 	flag = 0;
// 	i = 0;
// 	while (number_s--)
// 	{
// 		if (*(nc_s + position_s) == '\0')
// 			flag = 0;
// 		else if (*(nc_s + position_s) != '\0' && flag == 0)
// 		{
// 			return_value[i] = ft_strdup((const char *)(nc_s + position_s));
// 			if (!return_value[i])
// 				return (free_memory(return_value, i));
// 			i++;
// 			flag = 1;
// 		}
// 		position_s++;
// 	}
// 	return_value[i] = NULL;
// 	return (return_value);
// }

// // 区切り文字をヌル文字に置き換える
// void	deli_null(char *nc_s, char c)
// {
// 	while (*nc_s)
// 	{
// 		if (*nc_s == c)
// 			*nc_s = '\0';
// 		nc_s++;
// 	}
// }

// // 単語がいくつあるかをカウント
// // 単語の先頭にきたらflagを1にし単語数をカウント、flagの1の時は区切り文字でなくても条件を満たさない. 区切り文字にきたらflagを0にする
// // size_tをintのどっちを使った方がいいのか
// size_t	counter(char const *s, char c)
// {
// 	size_t	word_count;
// 	int		position_s;
// 	int		flag;

// 	flag = 0;
// 	position_s = 0;
// 	word_count = 0;
// 	while (*(s + position_s))
// 	{
// 		if (*(s + position_s) == c)
// 			flag = 0;
// 		else if (*(s + position_s) != c && flag == 0)
// 		{
// 			word_count++;
// 			flag = 1;
// 		}
// 		position_s++;
// 	}
// 	return (word_count);
// }

// // メモリ解放
// void	*free_memory(char **return_value, int i)
// {
// 	while (i > 0)
// 		free(return_value[i--]);
// 	free(return_value);
// 	return (NULL);
// }

// int	main(void)
// {
// 	// char	str[20] = "aa b    cc d ";
// 	char	**return_value_str;

// 	char	string[50] = "0 0 0 0 0 0 0 0 0";
// 	// char	string[20] = "aa bb cc dd";
// 	size_t	return_value;
// 	size_t	number;

// 	return_value = counter(string, ' ');
// 	printf("%zu\n", return_value);
// 	// printf("元の文字列：%s\n", string);
// 	number = strlen(string);
// 	// printf("元の文字列の文字数：%zu\n", number);
// 	return_value_str = ft_split(string, ' ');
// 	for (size_t i = 0; i <= return_value; i++)
// 		printf("%s\n", return_value_str[i]);
// }




// original
#include "libft.h"

char	*makeptr(char *s);
void	*free_memory(char **return_value, int i);
void	deli_null(char *nc_s, char c);
size_t	counter(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		position_s;
	int		flag;
	int		i;
	char	**return_value;
	char	*nc_s;
	size_t	number_s;

	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	number_s = ft_strlen(s);
	return_value = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!return_value)
		return (NULL);
	// ************************************ここ**********************************
	nc_s = makeptr((char *)s);
	deli_null(nc_s, c);
	position_s = 0;
	flag = 0;
	i = 0;
	while (number_s--)
	{
		if (*(nc_s + position_s) == '\0')
			flag = 0;
		else if (*(nc_s + position_s) != '\0' && flag == 0)
		{
			return_value[i] = ft_strdup((const char *)(nc_s + position_s));
			if (!return_value[i])
				return (free_memory(return_value, i));
			i++;
			flag = 1;
		}
		position_s++;
	}
	return_value[i] = NULL;
	return (return_value);
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

// int	main(void)
// {
// 	// char	str[20] = "aa b    cc d ";
// 	char	**return_value_str;

// 	char	*str="\0aa\0bbb";
// 	// char	*str = "aa bb cc dd";
// 	size_t	return_value;
// 	size_t	number;

// 	return_value = counter(str, '\0');
// 	printf("%zu\n", return_value);
// 	// printf("元の文字列：%s\n", string);
// 	number = strlen(str);
// 	// printf("元の文字列の文字数：%zu\n", number);
// 	return_value_str = ft_split(str, '\0');
// 	for (size_t i = 0; i <= return_value; i++)
// 		printf("%s\n", return_value_str[i]);
// }

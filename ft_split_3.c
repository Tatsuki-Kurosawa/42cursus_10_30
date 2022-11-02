#include "libft.h"
#include <unistd.h>

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
	size_t	number_exdeli;
	size_t	number_s;

	nc_s = (char *)s;
	while (*(nc_s) == c)
		nc_s++;
	number_s = ft_strlen(nc_s);
	// printf("number_sの値：%zu\n", number_s);
	// printf("nc_sの値：%s\n", nc_s);
	// printf("sの値：%s\n", s);
	number_exdeli = counter(s, c);
	return_value = (char **)malloc(number_exdeli + 1);
	if (!return_value)
		return (NULL);
	deli_null(nc_s, c);
	// printf("nc_sの値：%s\n", nc_s);
	position_s = 0;
	flag = 0;
	i = 0;
	while (number_s--)
	{
		if (*(nc_s + position_s) == '\0')
		{
			flag = 0;
			// printf("%c, %d, %d\n", *(nc_s + position_s), 0, flag);
		}
		else if (*(nc_s + position_s) != '\0' && flag == 0)
		{
			return_value[i] = ft_strdup((const char *)(nc_s + position_s));
			if (!return_value[i])
				return (free_memory(return_value, i));
			printf("while抜けるまえ：return_value[%d], %s\n", i, return_value[i]);
			i++;
			flag = 1;
			// printf("%c, %d, %d\n", *(nc_s + position_s), 1, flag);
		}
		position_s++;
	}
	printf("number_s : %zu\n", number_s);
	// .............................ここまでおけ....................................
	printf("%d\n", i);
	return_value[i] = NULL;
	printf("\n");
	while (i--)
		printf("while抜けたあと：return_value[%d], %s\n", i, return_value[i]);
	// printf("while抜けたあと：return_value[%d], %s\n", 6, return_value[6]);
	return (return_value);
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

// 	char	string[50] = "      split       this for   me  !       ";
// 	// char	string[20] = "aa bb cc dd";
// 	size_t	return_value;
// 	size_t	number;

// 	return_value = counter(string, ' ');
// 	// printf("%zu\n", return_value);
// 	printf("元の文字列：%s\n", string);
// 	number = strlen(string);
// 	printf("元の文字列の文字数：%zu\n", number);
// 	return_value_str = ft_split(string, ' ');
// 	for (size_t i = 0; i <= return_value; i++)
// 	// for (size_t i = 0; i < 5; i++)
// 		printf("%s\n", return_value_str[i]);
// }

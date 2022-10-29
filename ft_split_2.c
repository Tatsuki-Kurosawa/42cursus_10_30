#include "libft.h"

void	deli_null(char *nc_s, char c, size_t number_exdeli);
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
	char	*content;

	number_s = ft_strlen(s);
	number_exdeli = counter(s, c);
	return_value = (char **)malloc(number_exdeli);
	if (!return_value)
		return (NULL);
	nc_s = (char *)s;
	deli_null(nc_s, c, number_exdeli);
	position_s = 0;
	flag = 0;
	i = 0;
	while (number_s--)
	{
		if (*(nc_s + position_s) == '\0')
			flag = 0;
		else if (*(nc_s + position_s) != '\0' && flag == 0)
		{
			content = (char *)malloc(ft_strlen(nc_s + position_s));
			content = nc_s + position_s;
			return_value[i] = content;
			i++;
			flag = 1;
		}
		position_s++;
	}
	return (return_value);
}

// デリミタをヌル文字に置き換える
void	deli_null(char *nc_s, char c, size_t number_exdeli)
{
	int		position_s;
	int		flag;
	size_t	count;

	flag = 0;
	position_s = 0;
	count = 0;
	while (count < number_exdeli)
	{
		if (*(nc_s + position_s) == c)
		{
			*(nc_s + position_s) = '\0';
			flag = 0;
		}
		else if (*(nc_s + position_s) != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		position_s++;
	}
}

// 文字列の塊がいくつあるかをカウント
size_t	counter(char const *s, char c)
{
	size_t	number_memory;
	int		position_s;
	int		flag;

	flag = 0;
	position_s = 0;
	number_memory = 0;
	while (*(s + position_s))
	{
		if (*(s + position_s) == c)
			flag = 0;
		else if (*(s + position_s) != c && flag == 0)
		{
			number_memory++;
			flag = 1;
		}
		position_s++;
	}
	return (number_memory);
}

int	main(void)
{
	char	str[20] = " aa b    cc d ";
	char	**return_value_str;
	size_t	return_value;

	return_value = counter(str, ' ');
	// printf("%zu\n", return_value);
	return_value_str = ft_split(str, ' ');
	for (size_t i = 0; i < return_value; i++)
		printf("%s\n", *(return_value_str + i));
}



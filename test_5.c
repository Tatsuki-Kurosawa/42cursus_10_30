#include "libft.h"

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

int	main(void)
{
	// char	str[20] = "aa b    cc d ";
	// char	**return_value_str;

	char	*str="\0aa\0bbb";
	// char	*str = "aa bb cc dd";
	size_t	return_value;
	size_t	number;
	size_t	number_len;

	// return_value = counter(str, '\0');
	// printf("%zu\n", return_value);
	// printf("元の文字列：%s\n", string);
	number_len = strlen(str);
	// printf("元の文字列の文字数：%zu\n", number);
	number = counter(str, '\0');
	printf("number_len : %lu\n", number_len);
	printf("number : %lu\n", number);
}

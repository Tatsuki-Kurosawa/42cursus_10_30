#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*malloc_ptr;
	int		count_set;
	int		flag;

	malloc_ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!malloc_ptr)
		return (NULL);
	count_set = 0;
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		while (*(set + count_set) != '\0' || flag != 1)
		{
			if (ft_strchr(s1, *(set + count_set)) == NULL)
				flag = 1;
			count_set++;
		}
		count_set = 0;
		s1++;
	}
	// printf("%s\n", "通過");
	s1--;
	printf("%p\n", s1);
	malloc_ptr = (char *)s1;
	return (malloc_ptr);
	// return (back_check(malloc_ptr, set));
}

int	main(void)
{
	char	s1[12] = "1234AAA1212";
	char	set[5] = "1234";
	char	*return_value;

	return_value = ft_strtrim(s1, set);
	printf("%c\n", *return_value);
}
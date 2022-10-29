#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_ptr;
	size_t	count;

	// if (!s)
	if (s == NULL)
		return (NULL);
	return_ptr = (char *)malloc(len + 1);
	if (!return_ptr)
		return (NULL);
	else if (start >= ft_strlen(s) || len == 0)
	{
		*return_ptr = '\0';
		return (return_ptr);
	}
	else
	{
		count = 0;
		while (count < len)
		{
			if (*(s + start + count) == '\0')
			{
				*(return_ptr + count) = '\0';
				return (return_ptr);
			}
			*(return_ptr + count) = *(s + start + count);
			count++;
		}
		*(return_ptr + count) = '\0';
		return (return_ptr);
	}
}

// int	main(void)
// {
// 	char	str[40] = "i just want this part #############";
// 	size_t	size;
// 	char	*ret;

// 	size = 20;
// 	ret = ft_substr(NULL, 0, 12);
// 	if (ret == NULL)
// 		printf("%s\n", "NULLポインタカエテキテル");
// 	else
// 		// printf("ft_substr：%s, %zu\n", ret, strlen(ret));
// 		printf("%s\n", "NULLポインタカエテキテナイ");
// 	// printf("検証：%s, %zu\n", str + 5, strlen(str + 5));
// 	// if (!strncmp(ret, str + 5, size))
// 	// 	free(ret);
// }


// ヌルポインタ送った場合の処理ができてない？
// あと行数も
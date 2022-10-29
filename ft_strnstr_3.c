#include "libft.h"
#include <string.h>

char	*saiki(const char *hs, char *r_hs, char *r_nd, size_t hs_len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*r_haystack;
	char	*r_needle;
	size_t	haystack_len;

	haystack_len = len;
	r_haystack = (char *)haystack;
	r_needle = (char *)needle;
	if (!(*needle))
		return (r_haystack);
	while (haystack_len)
	{
		if (*r_haystack == *r_needle)
			return (saiki(haystack, ++r_haystack, ++r_needle, --haystack_len));
		r_haystack++;
		haystack_len--;
	}
	return (NULL);
}

char	*saiki(const char *hs, char *r_hs, char *r_nd, size_t hs_len)
{
	if (*r_nd == '\0')
		return ((char *)hs);
	else if (*r_nd != '\0' && hs_len == 0)
		return (NULL);
	if (*r_hs != *r_nd)
		return (NULL);
	else
	{
		while (*r_nd != '\0')
			return (saiki(++hs, r_hs, ++r_nd, --hs_len));
		return ((char *)hs);
	}
}

// int	main(void)
// {
// 	char	*p = ft_strnstr( "abcde", "", 2);
// 	puts(p);
// }

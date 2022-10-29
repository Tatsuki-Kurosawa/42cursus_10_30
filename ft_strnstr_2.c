#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hs;
	char	*hs_2;
	char	*nd;
	size_t	hs_len;
	size_t	hs_len_2;

	hs_len = len + 1;
	hs = (char *)haystack;
	nd = (char *)needle;
	if (!(*needle))
		return (hs);
	while (!(hs_len--))
	{
		if (*hs == *nd)
		{
			hs_2 = hs;
			hs_len_2 = hs_len;
			while ((*nd != '\0' || *hs == *nd) && !(hs_len--))
			{
				hs++;
				nd++;
			}
			if (*nd == '\0')
				return (hs);
			hs = hs_2;
			hs_len = hs_len_2;
		}
		hs++;
	}
	return (NULL);
}


int	main(void)
{
	char	*p = ft_strnstr( "abcde", "bc", 4 );
	printf("%c\n", *p);
}

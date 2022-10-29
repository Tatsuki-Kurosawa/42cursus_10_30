#include <stdio.h>
#include "libft.h"
#include <stdint.h>

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;
// 	size_t	number_of_byte;

// 	if (count == 0 || size == 0)
// 	{
// 		ptr = malloc(1);
// 		if(!ptr)
// 			return (NULL);
// 		ft_bzero(ptr, 1);
// 		return (ptr);
// 	}
// 	if (SIZE_MAX / count < size)
// 		return (NULL);
// 	number_of_byte = count * size;
// 	ptr = malloc(number_of_byte);
// 	if(!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, number_of_byte);
// 	return (ptr);
// }

void    *ft_calloc(size_t count, size_t size)
{
    void    *temp;

    if (size == 0 || count == 0)
    {
		size = 1;
		count = 1;
    }
	if (SIZE_MAX / size < count)
		return (NULL);
	temp = malloc(size * count);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, count * size);
    return (temp);
}

// void    *ft_calloc(size_t count, size_t size)
// {
//     void    *temp;

//     if (size == 0 || count == 0)
//     {
//         temp = malloc(1);
//         if (temp == NULL)
//             return (NULL);
//         ft_bzero(temp, 1);
//     }
//     else
//     {
//         if (SIZE_MAX / size < count)
//             return (NULL);
//         temp = malloc(size * count);
//         if (temp == NULL)
//             return (NULL);
//         ft_bzero(temp, count * size);
//     }
//     return (temp);
// }

// int	main(void)
// {
// 	char *ch;
//     ch = (char*)calloc(42,42);
// 	// ch = (char*)ft_calloc(0,0);
// 	puts("文字列を入力してください。");
//     gets(ch);
//     printf("入力した文字は→%s\n",ch);
//     free(ch);
//     return 0;
// }
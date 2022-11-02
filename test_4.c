#include "libft.h"

int	main(void)
{
	t_list	*ptr_1;
	t_list	*ptr_2;
	t_list	**head;

	ptr_1 = ft_lstnew("abcdef");
	printf("%s\n", (char *)ptr_1->content);
	printf("%p\n", ptr_1->next);
	ptr_2 = ft_lstnew("ghijkl");
	printf("%s\n", (char *)ptr_2->content);
	printf("%p\n", ptr_2->next);
	*head = ptr_1;
	ft_lstadd_front(head, ptr_2);
	printf("%p\n", ptr_1->next);
	printf("%p\n", ptr_2);
}

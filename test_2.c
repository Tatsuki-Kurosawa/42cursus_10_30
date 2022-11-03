#include <stdio.h>

int	main(void)
{
	typedef struct person
	{
		char	*name;
		int		age;
	}	t_person;

	t_person kozotai;
	kozotai.name = "abc";
	printf("%s", kozotai.name);
}

// 構造体を作成、この時の型は"struct 構造体名"
// 作った構造体の型をt_personと呼ぶことにする
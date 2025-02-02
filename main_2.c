#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*s;
	printf("%d\n", printf("%d | %i | %c | %s | %% | %p | %x | %X | %u\n",42, 42, 42, "test", s, 42, 42, 42));
	printf("%d\n", ft_printf("%d | %i | %c | %s | %% | %p | %x | %X | %u\n",42, 42, 42, "test", s, 42, 42, 42));

	printf("\n\n\n");

	printf("%d\n", printf("fkqbfshdf%dfjbseodifh\n",42));
	printf("%d\n", ft_printf("fkqbfshdf%dfjbseodifh\n",42));

	printf("\n\n\n");

	printf("fkqbfshdf%jbseodifh\n");
	ft_printf("fkqbfshdf%jbseodifh\n");

	printf("fkqbfshdf%bseodifh\n");
	ft_printf("fkqbfshdf%bseodifh\n");

	printf("fkqbfshdf%bseodifh\n", "Test");
	ft_printf("fkqbfshdf%bseodifh\n", "Test");

	printf("\n\n\n");

	printf("%d\n", printf("%\n"));
	printf("%d\n", ft_printf("%\n"));

	printf("\n\n\n");

	printf("%d\n", printf("%t\n"));
	printf("%d\n", ft_printf("%t\n"));

	printf("\n\n\n");

	printf("%d\n", printf("%"));
	printf("%d\n", ft_printf("%"));

	printf("\n\n\n");

	printf("%d\n", printf(NULL));
	printf("%d\n", ft_printf(NULL));

	printf("\n\n\n");

	printf("%d\n", printf("%c%%%s%p%%%d\n", 'c', "foqsidhf", s, 42));
	printf("%d\n", ft_printf("%c%%%s%p%%%d\n", 'c', "foqsidhf", s, 42));
}
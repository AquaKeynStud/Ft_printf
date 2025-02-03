#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{

	ft_printf("%i\n", printf(NULL));
	ft_printf("%i\n", ft_printf(NULL));

	printf("\n\n");

	ft_printf("%d\n", printf("%d\n", 42));
	ft_printf("%d\n", ft_printf("%d\n", 42));

	printf("\n\n");

	ft_printf("%i\n", printf("%i\n", 42));
	ft_printf("%i\n", ft_printf("%i\n", 42));

	printf("\n\n");

	ft_printf("%i\n", printf("%i\n", -52));
	ft_printf("%i\n", ft_printf("%i\n", -52));

	printf("\n\n");

	ft_printf("%i\n", printf("%i\n", 0));
	ft_printf("%i\n", ft_printf("%i\n", 0));

	printf("\n\n");

	ft_printf("%i\n", printf("%s\n", "Bonjour"));
	ft_printf("%i\n", ft_printf("%s\n", "Bonjour"));

	printf("\n\n");

	char *s = "Bonjour";

	ft_printf("%i\n", printf("%s%c%d%p\n", "Bonjour", 't', 42, s));
	ft_printf("%i\n", ft_printf("%s%c%d%p\n", "Bonjour", 't', 42, s));

	printf("\n\n");

	ft_printf("La vraie : %i\n", printf("%s\n", "")); fflush(stdout);
	ft_printf("La mienne : %i\n", ft_printf("%s\n", ""));

	printf("\n\n");

	ft_printf("La vraie : %i\n", printf("%s\n", NULL)); fflush(stdout);
	ft_printf("La mienne : %i\n", ft_printf("%s\n", NULL));

	printf("\n\n");

	ft_printf("La vraie : %i\n", printf("%x\n", 5616985196854)); fflush(stdout);
	ft_printf("La mienne : %i\n", ft_printf("%x\n", 5616985196854));

	printf("\n\n");

	ft_printf("La vraie : %i\n", printf("%X\n", 5616985196854)); fflush(stdout);
	ft_printf("La mienne : %i\n", ft_printf("%X\n", 5616985196854));

	printf("\n\n");

	ft_printf("La vraie : %i\n", printf("%c\n", 42)); fflush(stdout);
	ft_printf("La mienne : %i\n", ft_printf("%c\n", 42));

	printf("\n\n");

	ft_printf("La vraie : %i\n", printf("%u\n", 1671264521)); fflush(stdout);
	ft_printf("La mienne : %i\n", ft_printf("%u\n", 1671264521));
}

// printf("\n\n\n");
	
	// char	*s;
	// printf("%d\n", printf("%d | %i | %c | %s | %% | %p | %x | %X | %u\n",42, 42, 42, "test", s, 42, 42, 42));
	// printf("%d\n", ft_printf("%d | %i | %c | %s | %% | %p | %x | %X | %u\n",42, 42, 42, "test", s, 42, 42, 42));

	// printf("\n\n\n");

	// printf("%d\n", printf("fkqbfshdf%dfjbseodifh\n",42));
	// printf("%d\n", ft_printf("fkqbfshdf%dfjbseodifh\n",42));

	// printf("\n\n\n");

	// printf("fkqbfshdf%jbseodifh\n");
	// ft_printf("fkqbfshdf%jbseodifh\n");

	// printf("fkqbfshdf%bseodifh\n");
	// ft_printf("fkqbfshdf%bseodifh\n");

	// printf("fkqbfshdf%bseodifh\n", "Test");
	// ft_printf("fkqbfshdf%bseodifh\n", "Test");

	// printf("\n\n\n");

	// printf("%d\n", printf("%\n"));
	// printf("%d\n", ft_printf("%\n"));

	// printf("\n\n\n");

	// printf("%d\n", printf("%t\n"));
	// printf("%d\n", ft_printf("%t\n"));

	// printf("\n\n\n");

	// printf("%d\n", printf("%"));
	// printf("%d\n", ft_printf("%"));

	// printf("\n\n\n");

	// printf("%d\n", printf(NULL));
	// printf("%d\n", ft_printf(NULL));

	// printf("\n\n\n");

	// printf("%d\n", printf("%c%%%s%p%%%d\n", 'c', "foqsidhf", s, 42));
	// printf("%d\n", ft_printf("%c%%%s%p%%%d\n", 'c', "foqsidhf", s, 42));
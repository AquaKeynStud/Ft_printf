#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

int	stl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void custom_assert(int expr, const char *msg, float n_test) {
	float	total_test = 168;
	int		size_pan = 2;
    if (!expr) {
		printf("\e[31m╒");
		for (int i = 0; i < (stl(msg) + 21); i++)
		{
			size_pan += 1;
			printf("═");
		}
		printf("╕\n");
		printf("│");
		for (int i = 0; i < (stl(msg) + 21); i++)
			printf(" ");
		printf("│\n");
        fprintf(stderr, "│  Assertion error:\e[0m %s\e[31m", msg);
		for (int i = 0; i < 2; i++)
			printf(" ");
		printf("│\n");
		printf("│");
		for (int i = 0; i < (stl(msg) + 21); i++)
			printf(" ");
		printf("│\n");
		printf("│");
		for (int i = 0; i < (((stl(msg)) / 2) - 10 - ((stl(msg) + 21)%2 == 1)); i++)
			printf(" ");
		printf("\e[36m🫧  - Vous avez passé %05.2f%% des tests - 🫧\e[31m", (n_test / total_test) * 100);
		for (int i = 0; i < ((stl(msg) - 18) / 2); i++)
			printf(" ");
		printf("│\n");
		printf("│");
		for (int i = 0; i < (stl(msg) + 21); i++)
			printf(" ");
		printf("│\n");
		printf("╘");
		for (int i = 0; i < (stl(msg) + 21); i++)
			printf("═");
		printf("╛\e[0m\n");
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    int original, tested;

	printf("\n\n\e[36m╒══════════════════════════════════════════════╕\n");
	printf("│ 🫧  - ⚞ TESTEUR FT_PRINTF BONUS - KEYN ⚟ - 🫧  │\n");
	printf("│                                              │\n");
	printf("│               💉 - v1.0 - 💉                 │");
	printf("\n╘══════════════════════════════════════════════╛\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests flag - sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-d]", 1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-d]", 1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag `-`", 1);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-d]", -5); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-d]", -5); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag `-` (nombre négatif)", 2);

	printf("\e[37m╰━━━━═══╕出 ❖ ——————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests flag 0 sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0d]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0d]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag `0`", 3);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0d]", -10); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0d]", -10); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag `0` (nombre négatif)", 4);

	printf("\e[37m╰━━━━═══╕出 ❖ ——————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests flag . sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5i]", 42); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5i]", 42); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag `.`", 5);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5i]", -42); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5i]", -42); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag `.` (nombre négatif)", 6);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5i]", 623596); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5i]", 623596); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag `.` (nombre plus long que la précision)", 7);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.0i]", 53); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.0i]", 53); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag `.` (précision de 0)", 8);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.12i]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.12i]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 du flag `.` (valeur de 0)", 9);

	printf("\e[37m╰━━━━═══╕出 ❖ ——————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests flag + sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+d]", 362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+d]", 362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag `+`", 10);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+d]", -362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+d]", -362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag `+` (nombre négatif)", 11);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag `+` (valeur 0)", 12);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+d]", -2147483648); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+d]", -2147483648); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag `+` (valeur INT_MIN)", 13);

	printf("\e[37m╰━━━━═══╕出 ❖ ——————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests flag ' ' sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% d]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% d]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag ` `", 14);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag ` `", 14); //  new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% d]", -1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% d]", -1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag ` `", 14); //  new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% d]", -101); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% d]", -101); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag ` `", 14); //  new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% i]", -101); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% i]", -101); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag ` `", 14); //  new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% i | % i | % i | % i | % i | % i | % i]", INT_MIN, INT_MAX, LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX, LLONG_MAX); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% i | % i | % i | % i | % i | % i | % i]", INT_MIN, INT_MAX, LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX, LLONG_MAX); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag ` `", 14); //  new

	printf("\e[37m╰━━━━═══╕出 ❖ ————————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests flag # sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#d]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#d]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag `#`", 15);

	printf("\e[37m╰━━━━═══╕出 ❖ ——————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests largeur minimale sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-1d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-1d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 de largeur minimale (`-` + nombre positif)", 16); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10d]", 12); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10d]", 12); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 de largeur minimale (`-` + nombre positif)", 16);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10d]", -42); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10d]", -42); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 de largeur minimale (`-` + nombre négatif)", 17);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-15d]", -2147483648); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-15d]", -2147483648); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 de largeur minimale (`-` + INT_MIN)", 18);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010d]", 20); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010d]", 20); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 de largeur minimale (`0` + nombre positif)", 19);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010d]", -202); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010d]", -202); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 de largeur minimale (`0` + nombre négatif)", 20);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 de largeur minimale (`0` + valeur 0)", 21);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10d]", 5362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10d]", 5362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 de largeur minimale (`+` + nombre positif)", 22);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10d]", -5362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10d]", -5362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 de largeur minimale (`+` + nombre négatif)", 23);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#5d]", 23); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#5d]", 23); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 de largeur minimale (`#`)", 24);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% 5d]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% 5d]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 de largeur minimale (` `)", 25);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%- 5d]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%- 5d]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 de largeur minimale (` ` + `-`)", 26);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-12d]", LONG_MIN); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-12d]", LONG_MIN); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 de largeur minimale (` ` + `-`)", 26); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-9d %-10d %-11d %-12d %-13d %-14d %-15d]", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-9d %-10d %-11d %-12d %-13d %-14d %-15d]", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 de largeur minimale (` ` + `-`)", 26); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-13i]", UINT_MAX); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-13i]", UINT_MAX); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 de largeur minimale (` ` + `-`)", 26); // new

	printf("\e[37m╰━━━━═══╕出 ❖ —————————————————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de précision combinée sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.5d]", 56); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.5d]", 56); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 de précision combinée (largeur minimale)", 27);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.5d]", -56); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.5d]", -56); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 de précision combinée (largeur minimale + nombre négatif)", 28);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%20.15d]", -2147483648); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%20.15d]", -2147483648); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 de précision combinée (largeur minimale + INT_MIN)", 29);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%20.15d]", 2147483647); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%20.15d]", 2147483647); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 de précision combinée (largeur minimale + INT_MAX)", 30);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%15.20d]", 754); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%15.20d]", 754); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 de précision combinée (largeur minimale < précision)", 31);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.0d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.0d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 de précision combinée (largeur minimale + 0)", 32);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10.0d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10.0d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 de précision combinée (largeur minimale + `-` + 0)", 33);

	printf("\e[37m╰━━━━═══╕出 ❖ —————————————————————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests en tous genres sur %%d et %%i ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% .5d]", 69); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% .5d]", 69); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 en tous genre (` ` + `.` + largeur minimale)", 34);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+10.5d]", 32); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+10.5d]", 32); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 en tous genre (`-` + `+` + `.` + largeur minimale)", 35);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+10.5d]", 753); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+10.5d]", 753); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 en tous genre (`0` + `-` + `+` + `.` + largeur minimale)", 36);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+ #25.8d]", 42153); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+ #25.8d]", 42153); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 en tous genre (tous les flags)", 37);

	printf("\e[37m╰━━━━═══╕出 ❖ ——————————————————————————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%c ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-c]", 'a'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-c]", 'a'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 de %c", 38);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10c]", 'b'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10c]", 'b'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 de %c", 39);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10c]", 'c'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10c]", 'c'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 de %c", 40);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010c]", 'd'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010c]", 'd'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 de %c", 41);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-10c]", 'e'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-10c]", 'e'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 de %c", 42);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.5c]", 'f'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.5c]", 'f'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 de %c", 43);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10c]", 'g'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10c]", 'g'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 de %c", 44);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#10c]", 'h'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#10c]", 'h'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 de %c", 45);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% 10c]", 'i'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% 10c]", 'i'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 de %c", 46);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0c]", 'j'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0c]", 'j'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 de %c", 47);

	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%p ❖ 力╒═══━━━━╮\e[0m\n\n");

	char *str = "Ce week-end je vais à un camping sur un îlot.";

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%25p]", INT_MIN); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%25p]", INT_MIN); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 de %p (avec INT_MIN)", 48);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-25p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-25p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 de %p", 49);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%030p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%030p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 de %p", 50);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-30p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-30p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 de %p", 51);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 de %p", 52);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 de %p", 53);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.25p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.25p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 de %p", 54);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 de %p", 55);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+ #025.5p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+ #025.5p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 de %p", 56);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10p]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10p]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 de %p (avec `+` valeur 0)", 57);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+10p]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+10p]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 de %p (avec `-` + `+` et valeur 0)", 58);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+ 10p]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+ 10p]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 12 de %p (avec ` ` + `+` et valeur 0)", 59);

	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%u ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-u]", 1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-u]", 1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag %u (avec `-`)", 60);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0u]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0u]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag %u (avec `0`)", 61);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5u]", 42); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5u]", 42); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag %u (avec `.`)", 62);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5u]", 623596); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5u]", 623596); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag %u (nombre plus long que la précision)", 63);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.0u]", 53); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.0u]", 53); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 du flag %u (précision de 0)", 64);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.12u]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.12u]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 du flag %u (`.` et valeur 0)", 65);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+u]", 362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+u]", 362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 du flag %u", 66);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+d]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+d]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 du flag %u (`+` et valeur 0)", 67);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% u]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% u]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 du flag %u (avec ` `)", 68);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#u]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#u]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 du flag %u (avec `#`)", 69);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10u]", 12); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10u]", 12); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 du flag %u (`-` + largeur minimale)", 70);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010u]", 20); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010u]", 20); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 12 du flag %u (`0` + largeur minimale)", 71);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010u]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010u]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 13 du flag %u (`0` + valeur 0 + largeur minimale)", 72);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10u]", 5362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10u]", 5362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 14 du flag %u (`+` + largeur minimale)", 73);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#5u]", 23); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#5u]", 23); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 15 du flag %u (`#` + largeur minimale)", 74);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% 5u]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% 5u]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 16 du flag %u (` ` + largeur minimale)", 75);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%- 5u]", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%- 5u]", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 17 du flag %u (` ` + `-` + largeur minimale)", 76);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.5u]", 56); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.5u]", 56); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 18 du flag %u (précision combinée)", 77);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%20.15u]", 2147483647); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%20.15u]", 2147483647); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 19 du flag %u (précision combinée + INT_MAX)", 78);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%15.20u]", 754); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%15.20u]", 754); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 20 du flag %u (largeur minimale < précision)", 79);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.0u]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.0u]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 21 du flag %u (largeur minimale + 0)", 80);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10.0u]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10.0u]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 22 du flag %u (largeur minimale + `-` + 0)", 81);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% .5u]", 69); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% .5u]", 69); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 23 du flag %u (` ` + `.` + largeur minimale)", 82);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+10.5u]", 32); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+10.5u]", 32); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 24 du flag %u (`-` + `+` + `.` + largeur minimale)", 83);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+10.5u]", 753); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+10.5u]", 753); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 25 du flag %u (`0` + `-` + `+` + `.` + largeur minimale)", 84);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+ #25.8u]", 42153); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+ #25.8u]", 42153); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-1u]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-1u]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-2u]", -1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-2u]", -1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-12u %-13u %-14u %-15u]", LONG_MIN, UINT_MAX, ULONG_MAX, LLONG_MAX); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-12u %-13u %-14u %-15u]", LONG_MIN, UINT_MAX, ULONG_MAX, LLONG_MAX); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%03u]", 1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%03u]", 1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%05u]", -15); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%05u]", -15); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%01u]", -99); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%01u]", -99); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%012u %014u %015u]", LONG_MIN, ULONG_MAX, LLONG_MAX); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%012u %014u %015u]", LONG_MIN, ULONG_MAX, LLONG_MAX); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.2u]", -1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.2u]", -1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.10u]", ULONG_MAX); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.10u]", ULONG_MAX); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %u (tous les flags)", 85); // new

	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%% ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag %% (`-`)", 86);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag %% (`.`)", 87);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag %% (`+`)", 88);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%05%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%05%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag %% (`0`)", 89);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 du flag %% (`#`)", 90);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% %]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% %]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 du flag %% (` `)", 91);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 du flag %% (largeur minimale)", 92);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 du flag %% (`-` + largeur minimale)", 93);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 du flag %% (`0` + largeur minimale)", 94);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+10.5%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+10.5%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 du flag %% (combinaison de flags)", 95);

	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%x ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-x]", 1235); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-x]", 1235); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag %x (avec `-`)", 96);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0x]", 2164); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0x]", 2164); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag %x (avec `0`)", 97);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5x]", 13462); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5x]", 13462); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag %x (avec `.`)", 98);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.2x]", 134623567); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.2x]", 134623567); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag %x (nombre plus long que la précision)", 99);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.0x]", 1253); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.0x]", 1253); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 du flag %x (précision de 0)", 100);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.12x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.12x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 du flag %x (`.` et valeur 0)", 101);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+x]", 43563); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+x]", 43563); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 du flag %x", 102);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 du flag %x (`+` et valeur 0)", 103);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% x]", 423); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% x]", 423); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 du flag %x (avec ` `)", 104);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#x]", 2765); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#x]", 2765); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 du flag %x (avec `#`)", 105);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10x]", 14232); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10x]", 14232); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 du flag %x (`-` + largeur minimale)", 106);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010x]", 436689); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010x]", 436689); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 12 du flag %x (`0` + largeur minimale)", 107);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 13 du flag %x (`0` + valeur 0 + largeur minimale)", 108);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10x]", 5362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10x]", 5362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 14 du flag %x (`+` + largeur minimale)", 109);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#5x]", 765963); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#5x]", 765963); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 15 du flag %x (`#` + largeur minimale)", 110);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% 5x]", 27566); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% 5x]", 27566); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 16 du flag %x (` ` + largeur minimale)", 111);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%- 5x]", 27693); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%- 5x]", 27693); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 17 du flag %x (` ` + `-` + largeur minimale)", 112);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.5x]", 516); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.5x]", 516); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 18 du flag %x (précision combinée)", 113);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%20.10x]", 4294967295); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%20.10x]", 4294967295); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 19 du flag %x (précision combinée + UINT_MAX)", 114);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%15.20x]", 13462); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%15.20x]", 13462); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 20 du flag %x (largeur minimale < précision)", 115);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.0x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.0x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 21 du flag %x (largeur minimale + 0)", 116);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10.0x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10.0x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 22 du flag %x (largeur minimale + `-` + 0)", 117);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% .5x]", 6975); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% .5x]", 6975); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 23 du flag %x (` ` + `.` + largeur minimale)", 118);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+10.5x]", 3243); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+10.5x]", 3243); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 24 du flag %x (`-` + `+` + `.` + largeur minimale)", 119);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+10.5x]", 75343); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+10.5x]", 75343); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 25 du flag %x (`0` + `-` + `+` + `.` + largeur minimale)", 120);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+ #25.8x]", 42153); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+ #25.8x]", 42153); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %x (tous les flags)", 121);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-1x]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-1x]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-2x]", -1); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-2x]", -1); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-13x]", UINT_MAX); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-13x]", UINT_MAX); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new


	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%X ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-X]", 1235); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-X]", 1235); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag %X (avec `-`)", 122);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0X]", 2164); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0X]", 2164); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag %X (avec `0`)", 123);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5X]", 13462); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5X]", 13462); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag %X (avec `.`)", 124);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.2X]", 134623567); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.2X]", 134623567); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag %X (nombre plus long que la précision)", 125);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.0X]", 1253); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.0X]", 1253); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 du flag %X (précision de 0)", 126);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.12X]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.12X]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 du flag %X (`.` et valeur 0)", 127);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+X]", 43563); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+X]", 43563); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 du flag %X", 128);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+X]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+X]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 du flag %X (`+` et valeur 0)", 129);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% X]", 423); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% X]", 423); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 du flag %X (avec ` `)", 130);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#X]", 2765); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#X]", 2765); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 du flag %X (avec `#`)", 131);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10X]", 14232); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10X]", 14232); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 11 du flag %X (`-` + largeur minimale)", 132);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010X]", 436689); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010X]", 436689); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 12 du flag %X (`0` + largeur minimale)", 133);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%010X]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%010X]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 13 du flag %X (`0` + valeur 0 + largeur minimale)", 134);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+10X]", 5362); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+10X]", 5362); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 14 du flag %X (`+` + largeur minimale)", 135);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#5X]", 765963); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#5X]", 765963); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 15 du flag %X (`#` + largeur minimale)", 136);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% 5X]", 27566); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% 5X]", 27566); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 16 du flag %X (` ` + largeur minimale)", 137);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%- 5X]", 27693); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%- 5X]", 27693); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 17 du flag %X (` ` + `-` + largeur minimale)", 138);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.5X]", 516); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.5X]", 516); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 18 du flag %X (précision combinée)", 139);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%20.10X]", 4294967295); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%20.10X]", 4294967295); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 19 du flag %X (précision combinée + UINT_MAX)", 140);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%15.20X]", 13462); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%15.20X]", 13462); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 20 du flag %X (largeur minimale < précision)", 141);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10.0X]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10.0X]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 21 du flag %X (largeur minimale + 0)", 142);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10.0X]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10.0X]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 22 du flag %X (largeur minimale + `-` + 0)", 143);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% .5X]", 6975); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% .5X]", 6975); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 23 du flag %X (` ` + `.` + largeur minimale)", 144);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-+10.5X]", 3243); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-+10.5X]", 3243); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 24 du flag %X (`-` + `+` + `.` + largeur minimale)", 145);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+10.5X]", 75343); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+10.5X]", 75343); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 25 du flag %X (`0` + `-` + `+` + `.` + largeur minimale)", 146);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-+ #25.8X]", 42153); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-+ #25.8X]", 42153); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 26 du flag %X (tous les flags)", 147);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%01X]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%01X]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%05X]", 17); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%05X]", 17); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5X]", 16); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5X]", 16); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#X %#X %#X %#X %#X %#X %#X]", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#X %#X %#X %#X %#X %#X %#X]", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 27 du flag %x (`#`)", 122); // new

	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests de %%s ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-s]", "Coraline"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-s]", "Coraline"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 du flag %s (`-`)", 148);
	
	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0s]", "Chauve-Souris"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0s]", "Chauve-Souris"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 du flag %s (`0`)", 149);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%.5s]", "Vietnam"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%.5s]", "Vietnam"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 du flag %s (`.`)", 150);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%+s]", "Little"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%+s]", "Little"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 du flag %s (`+`)", 151);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[% s]", "Alchemy"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[% s]", "Alchemy"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 du flag %s (` `)", 152);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%#s]", "Chaton"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%#s]", "Chaton"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 du flag %s (`#`)", 153);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-30s]", "Stardew Valley"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-30s]", "Stardew Valley"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 du flag %s (`-` + largeur minimale)", 154);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-10.7s]", "Stardew Valley"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-10.7s]", "Stardew Valley"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 du flag %s (`-` + largeur minimale + précision)", 155);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-0+ #10.7s]", "Stardew Valley"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-0+ #10.7s]", "Stardew Valley"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 9 du flag %s (tous les flags)", 156);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-0+ #10.7s]", ""); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-0+ #10.7s]", ""); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 10 du flag %s (tous les flags + chaine vide)", 157);

	printf("\e[37m╰━━━━═══╕出 ❖ ———————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[37m╭━━━━═══╕出 ❖ tests erreurs ❖ 力╒═══━━━━╮\e[0m\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-5 .5d]", 25); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-5 .5d]", 25); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 erreur", 158);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%0-5 .5i]", 25); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%0-5 .5i]", 25); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 erreur", 159);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10 20p]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10 20p]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 erreur", 160);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%10 10%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%10 10%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 erreur", 161);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%-25# 10x]", 2536); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%-25# 10x]", 2536); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 erreur", 162);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%30. 10X]", 2536); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%30. 10X]", 2536); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 erreur", 163);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%9 1s]", "Stardew Valley"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%9 1s]", "Stardew Valley"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 6 erreur", 164);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%9 12u]", 164); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%9 12u]", 164); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 7 erreur", 165);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%9-12c]", 'u'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original); fflush(stdout);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%9-12c]", 'u'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 8 erreur", 166);

	printf("\e[37m╰━━━━═══╕出 ❖ ————————————— ❖ 力╒═══━━━━╯\e[0m\n\n\n");

	printf("\e[32m╒═══════════════════════════════════════════╕\n");
	printf("│ ✅ - ⚞ Tests passés avec succès !! ⚟ - ✅ │");
	printf("\n╘═══════════════════════════════════════════╛\e[0m\n");

    return 0;
}

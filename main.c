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
	float	total_test = 44;
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

int	main(void)
{
	int original, tested;

	printf("\n\n\e[36m╒════════════════════════════════════════╕\n");
	printf("│ 🫧  - ⚞ TESTEUR FT_PRINTF - KEYN ⚟ - 🫧  │\n");
	printf("│                                        │\n");
	printf("│             💉 - v2.0 - 💉             │");
	printf("\n╘════════════════════════════════════════╛\e[0m\n\n\n");
	
	printf("╭━━━━═══╕出 ❖ tests pourcentage [%s] ❖ 力╒═══━━━━╮\n\n", "%%");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%%]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%%]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test de taille du pourcentage n'est pas passé D:\n", 1);

	printf("╰━━━━═══╕出 ❖ ——————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests character [%s] ❖ 力╒═══━━━━╮\n\n", "%c");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%c %c %c]", 'a', '\t', '!'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%c %c %c]", 'a', '\t', '!'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des caractères (basique)", 2);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[Hello Worl%c !]", 'd'); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[Hello Worl%c !]", 'd'); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des caractères (dans une chaîne)", 3);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%c]", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%c]", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des caractères (caractère nul)", 4);


	printf("╰━━━━═══╕出 ❖ ———————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests string [%s] ❖ 力╒═══━━━━╮\n\n", "%s");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s]", "Demain je vais au cinéma"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s]", "Demain je vais au cinéma"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des strings (basique)", 5);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%cinalement %s]", 'F', "je n'y vais plus."); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%cinalement %s]", 'F', "je n'y vais plus."); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des strings (Après un autre affichage)", 6);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s]", ""); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s]", ""); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des strings (chaine vide)", 7);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des strings (aucun paramètre)", 8);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 5 des strings (avec NULL)", 9);

	printf("╰━━━━═══╕出 ❖ ————————————————— ❖ 力╒═══━━━━╯\n\n\n");



	printf("╭━━━━═══╕出 ❖ tests integer [%s] ❖ 力╒═══━━━━╮\n\n", "%i");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%i]", 25); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%i]", 25); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des integer %i (basique)", 10);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s : %i]", "Valeur int min", -2147483648); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s : %i]", "Valeur int min", -2147483648); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des integer %i (valeur int min)", 11);

	printf("⤐ Optionnel ⬷\n");
	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%i]", -2147483699); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%i]", -2147483699); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%i]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%i]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des integer %i (aucun paramètre)", 12);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%i]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%i]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des integer %i (avec NULL)", 13);

	printf("╰━━━━═══╕出 ❖ —————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests decimal [%s] ❖ 力╒═══━━━━╮\n\n", "%d");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%d]", 25); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%d]", 25); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des decimal %d (basique)", 14);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s : %d]", "Valeur int min", -2147483648); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s : %d]", "Valeur int min", -2147483648); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des decimal %d (valeur int min)", 15);

	printf("⤐ Optionnel ⬷\n");
	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%d]", -2147483699); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%d]", -2147483699); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%d]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%d]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des decimal %d (aucun paramètre)", 16);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%d]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%d]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des decimal %d (avec NULL)", 17);

	printf("╰━━━━═══╕出 ❖ —————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests unsigned int [%s] ❖ 力╒═══━━━━╮\n\n", "%u");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%u]", 25); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%u]", 25); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des unsigned int %u (basique)", 18);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s : %u]", "Valeur unsigned max", 4294967295); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s : %u]", "Valeur unsigned max", 4294967295); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des unsigned int %u (valeur unsigned max)", 19);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s : %u]", "Valeur 0", 0); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s : %u]", "Valeur 0", 0); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des unsigned int %u (valeur 0)", 20);

	printf("⤐ Optionnel ⬷\n");
	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%u]", -21474); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%u]", -21474); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%u]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%u]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des unsigned int %u (aucun paramètre)", 21);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%u]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%u]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 5 des unsigned int %u (avec NULL)", 22);

	printf("╰━━━━═══╕出 ❖ ——————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests lowercase hexadecimal [%s] ❖ 力╒═══━━━━╮\n\n", "%x");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%x]", 42949672); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%x]", 42949672); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des hexadecimaux en minuscule (basique)", 23);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s : %x]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s : %x]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des hexadecimaux en minuscule (valeur unsigned int max)", 24);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%x]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%x]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des hexadecimaux en minuscule (aucun paramètre)", 25);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%x]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%x]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des hexadecimaux en minuscule (avec NULL)", 26);

	printf("╰━━━━═══╕出 ❖ ———————————————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests uppercase hexadecimal [%s] ❖ 力╒═══━━━━╮\n\n", "%X");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%X]", 256516); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%X]", 256516); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des hexadecimaux en majuscule (basique)", 27);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%s : %X]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%s : %X]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des hexadecimaux en majuscule (valeur unsigned int max)", 28);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%X]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%X]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des hexadecimaux en majuscule (aucun paramètre)", 29);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%X]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%X]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des hexadecimaux en majuscule (avec NULL)", 30);

	printf("╰━━━━═══╕出 ❖ ———————————————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests address [%s] ❖ 力╒═══━━━━╮\n\n", "%p");

	char *str = "Ce week-end je vais à un camping sur un îlot.";

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%p]", str); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%p]", str); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 1 des adresses en minuscule (basique)", 31);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%p]"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%p]"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 2 des adresses en minuscule (avec NULL)", 32);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%p]", NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%p]", NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 3 des adresses en minuscule (avec NULL)", 33);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%p]", INT_MIN); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%p]", INT_MIN); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Erreur sur le test 4 des adresses en minuscule (avec INT_MIN)", 34);

	printf("╰━━━━═══╕出 ❖ ——————————————————————— ❖ 力╒═══━━━━╯\n\n\n");

	printf("╭━━━━═══╕出 ❖ tests mix + tests persos ❖ 力╒═══━━━━╮\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("[%d%%%c%s blblblbl%s  %d]", 100, '.', "Test passé", "test", 2); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("[%d%%%c%s blblblbl%s  %d]", 100, '.', "Test passé", "test", 2); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sur une fausse conversion en milieu de texte n'est pas passé D:\n", 35);

	printf("╰━━━━═══╕出 ❖ ————————————— ❖ 力═══━━━━╯\n\n\n");

	printf("╭━━━━═══╕出 ❖ tests erreurs ❖ 力╒═══━━━━╮\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("%z"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("%z"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sur une conversion impossible n'est pas passé D:\n", 36);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("%"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("%"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans conversion n'est pas passé D:\n", 37);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf(NULL); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf(NULL); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n", 38);

	printf("\e[31m");
	printf("╒═════════════════════════════════════════════════════════════════════════╕\n");
	printf("│                          🪼 - ⚞ DISCLAIMER ⚟ - 🪼                         │\n");
	printf("╘═════╕                                                             ╒═════╛\n");
	printf("      │         Les tests qui vont suivre sont plus poussés         │\n");
	printf("      │          ils vous obligeraient surement à modifier          │\n");
	printf("      │               une grande partie de votre code               │\n");
	printf("      │                                                             │\n");
	printf("      │    Entre nous, ces tests ne faisant pas partie du sujet,    │\n");
	printf("      │                ils devraient être négligés.                 │\n");
	printf("      │    (leur résultat avec printf peuvent être aléatoires...)   │\n");
	printf("      │                                                             │\n");
	printf("      │      Ils ont cependant étés réalisés pour quelques uns      │\n");
	printf("      │           pendant mes évaluations, soyez prudents           │\n");
	printf("      ╘═════════════════════════════════════════════════════════════╛\n\n\n");

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("%zqsf"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("%zqsf"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n", 39);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("%zsqsf"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("%zsqsf"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n", 40);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("%zsqsf %s", "Bonjour"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("%zsqsf %s", "Bonjour"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n", 41);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("LeTestDeFou%zLeTestDeFou"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("LeTestDeFou%zLeTestDeFou"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n", 42);

	printf("\e[34mOriginal : \e[0m"); fflush(stdout); original = printf("C'est le dernier%qqqzC'est le dernier"); fflush(stdout); printf("\e[34m	| {%i}\e[0m\n", original);
	printf("\e[36mTested :   \e[0m"); fflush(stdout); tested = ft_printf("C'est le dernier%qqqzC'est le dernier"); fflush(stdout); printf("\e[36m	| {%i}\e[0m\n\n", tested);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n", 43);

	printf("╰━━━━═══╕出 ❖ ————————————— ❖ 力╒═══━━━━╯\n\n\n");

	printf("\e[32m╒═══════════════════════════════════════════╕\n");
	printf("│ ✅ - ⚞ Tests passés avec succès !! ⚟ - ✅ │");
	printf("\n╘═══════════════════════════════════════════╛\e[0m\n");

	return (0);
}
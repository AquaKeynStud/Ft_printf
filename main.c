#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

void custom_assert(int expr, const char *msg) {
    if (!expr) {
        fprintf(stderr, "Assertion failed: %s\n", msg);
        exit(EXIT_FAILURE);
    }
}

int	main(void)
{
	int original, tested;
	
	printf("╭━━━━═══╕出 ❖ tests pourcentage [%s] ❖ 力╒═══━━━━╮\n\n", "%%");

	printf("Original : "); fflush(stdout); original = printf("[%%]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%%]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Le test de taille du pourcentage n'est pas passé D:\n");

	printf("╰━━━━═══╕出 ❖ ——————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests character [%s] ❖ 力╒═══━━━━╮\n\n", "%c");

	printf("Original : "); fflush(stdout); original = printf("[%c %c %c]", 'a', '\t', '!'); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%c %c %c]", 'a', '\t', '!'); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des caractères (basique)");

	printf("Original : "); fflush(stdout); original = printf("[Hello Worl%c !]", 'd'); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[Hello Worl%c !]", 'd'); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des caractères (dans une chaîne)");

	printf("Original : "); fflush(stdout); original = printf("[%c]", 0); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%c]", 0); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des caractères (caractère nul)");


	printf("╰━━━━═══╕出 ❖ ———————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests string [%s] ❖ 力╒═══━━━━╮\n\n", "%s");

	printf("Original : "); fflush(stdout); original = printf("[%s]", "Demain je vais au cinéma"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s]", "Demain je vais au cinéma"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des strings (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%cinalement %s]", 'F', "je n'y vais plus."); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%cinalement %s]", 'F', "je n'y vais plus."); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des strings (Après un autre affichage)");

	printf("Original : "); fflush(stdout); original = printf("[%s]", ""); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s]", ""); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des strings (chaine vide)");

	printf("Original : "); fflush(stdout); original = printf("[%s]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des strings (aucun paramètre)");

	printf("Original : "); fflush(stdout); original = printf("[%s]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 des strings (avec NULL)");

	printf("╰━━━━═══╕出 ❖ ————————————————— ❖ 力╒═══━━━━╯\n\n\n");



	printf("╭━━━━═══╕出 ❖ tests integer [%s] ❖ 力╒═══━━━━╮\n\n", "%i");

	printf("Original : "); fflush(stdout); original = printf("[%i]", 25); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%i]", 25); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des integer %i (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%s : %i]", "Valeur int min", -2147483648); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s : %i]", "Valeur int min", -2147483648); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des integer %i (valeur int min)");

	printf("⤐ Optionnel ⬷\n");
	printf("Original : "); fflush(stdout); original = printf("[%i]", -2147483699); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%i]", -2147483699); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);

	printf("Original : "); fflush(stdout); original = printf("[%i]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%i]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des integer %i (aucun paramètre)");

	printf("Original : "); fflush(stdout); original = printf("[%i]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%i]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des integer %i (avec NULL)");

	printf("╰━━━━═══╕出 ❖ —————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests decimal [%s] ❖ 力╒═══━━━━╮\n\n", "%d");

	printf("Original : "); fflush(stdout); original = printf("[%d]", 25); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%d]", 25); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des decimal %d (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%s : %d]", "Valeur int min", -2147483648); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s : %d]", "Valeur int min", -2147483648); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des decimal %d (valeur int min)");

	printf("⤐ Optionnel ⬷\n");
	printf("Original : "); fflush(stdout); original = printf("[%d]", -2147483699); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%d]", -2147483699); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);

	printf("Original : "); fflush(stdout); original = printf("[%d]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%d]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des decimal %d (aucun paramètre)");

	printf("Original : "); fflush(stdout); original = printf("[%d]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%d]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des decimal %d (avec NULL)");

	printf("╰━━━━═══╕出 ❖ —————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests unsigned int [%s] ❖ 力╒═══━━━━╮\n\n", "%u");

	printf("Original : "); fflush(stdout); original = printf("[%u]", 25); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%u]", 25); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des unsigned int %u (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%s : %u]", "Valeur unsigned max", 4294967295); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s : %u]", "Valeur unsigned max", 4294967295); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des unsigned int %u (valeur unsigned max)");

	printf("Original : "); fflush(stdout); original = printf("[%s : %u]", "Valeur 0", 0); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s : %u]", "Valeur 0", 0); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des unsigned int %u (valeur 0)");

	printf("⤐ Optionnel ⬷\n");
	printf("Original : "); fflush(stdout); original = printf("[%u]", -21474); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%u]", -21474); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);

	printf("Original : "); fflush(stdout); original = printf("[%u]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%u]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des unsigned int %u (aucun paramètre)");

	printf("Original : "); fflush(stdout); original = printf("[%u]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%u]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 5 des unsigned int %u (avec NULL)");

	printf("╰━━━━═══╕出 ❖ ——————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests lowercase hexadecimal [%s] ❖ 力╒═══━━━━╮\n\n", "%x");

	printf("Original : "); fflush(stdout); original = printf("[%x]", 42949672); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%x]", 42949672); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des hexadecimaux en minuscule (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%s : %x]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s : %x]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des hexadecimaux en minuscule (valeur unsigned int max)");

	printf("Original : "); fflush(stdout); original = printf("[%x]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%x]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des hexadecimaux en minuscule (aucun paramètre)");

	printf("Original : "); fflush(stdout); original = printf("[%x]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%x]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des hexadecimaux en minuscule (avec NULL)");

	printf("╰━━━━═══╕出 ❖ ———————————————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests uppercase hexadecimal [%s] ❖ 力╒═══━━━━╮\n\n", "%X");

	printf("Original : "); fflush(stdout); original = printf("[%X]", 256516); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%X]", 256516); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des hexadecimaux en majuscule (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%s : %X]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%s : %X]", "Valeur unsigned int max", 4294967295); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des hexadecimaux en majuscule (valeur unsigned int max)");

	printf("Original : "); fflush(stdout); original = printf("[%X]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%X]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des hexadecimaux en majuscule (aucun paramètre)");

	printf("Original : "); fflush(stdout); original = printf("[%X]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%X]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des hexadecimaux en majuscule (avec NULL)");

	printf("╰━━━━═══╕出 ❖ ———————————————————————————————— ❖ 力╒═══━━━━╯\n\n\n");


	printf("╭━━━━═══╕出 ❖ tests address [%s] ❖ 力╒═══━━━━╮\n\n", "%p");

	char *str = "Ce week-end je vais à un camping sur un îlot.";

	printf("Original : "); fflush(stdout); original = printf("[%p]", str); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%p]", str); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 1 des adresses en minuscule (basique)");

	printf("Original : "); fflush(stdout); original = printf("[%p]"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%p]"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 2 des adresses en minuscule (avec NULL)");

	printf("Original : "); fflush(stdout); original = printf("[%p]", NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%p]", NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 3 des adresses en minuscule (avec NULL)");

	printf("Original : "); fflush(stdout); original = printf("[%p]", INT_MIN); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%p]", INT_MIN); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Erreur sur le test 4 des adresses en minuscule (avec INT_MIN)");

	printf("╰━━━━═══╕出 ❖ ——————————————————————— ❖ 力╒═══━━━━╯\n\n\n");

	printf("╭━━━━═══╕出 ❖ tests erreurs ❖ 力╒═══━━━━╮\n\n");

	printf("Original : "); fflush(stdout); original = printf("%z"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("%z"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Le test sur une conversion impossible n'est pas passé D:\n");

	printf("Original : "); fflush(stdout); original = printf("%"); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("%"); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Le test sans conversion n'est pas passé D:\n");

	printf("Original : "); fflush(stdout); original = printf(NULL); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf(NULL); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Le test sans format n'est pas passé D:\n");

	printf("╰━━━━═══╕出 ❖ ————————————— ❖ 力╒═══━━━━╯\n\n\n");

	printf("╭━━━━═══╕出 ❖ tests mix + tests persos ❖ 力╒═══━━━━╮\n\n");

	printf("Original : "); fflush(stdout); original = printf("[%d%%%c%s blblblbl%s  %d]", 100, '.', "Test passé", "test", 2); fflush(stdout); printf("	| {%i}\n", original); fflush(stdout);
	printf("Tested :   "); fflush(stdout); tested = ft_printf("[%d%%%c%s blblblbl%s  %d]", 100, '.', "Test passé", "test", 2); fflush(stdout); printf("	| {%i}\n\n", tested); fflush(stdout);
	custom_assert(original == tested, "Le test sur une fausse conversion en milieu de texte n'est pas passé D:\n");

	printf("╰━━━━═══╕出 ❖ ————————————— ❖ 力═══━━━━╯\n\n\n");

	printf("\e[32m╒═══════════════════════════════════════════╕\n");
	printf("│ ✅ - ⚞ Tests passés avec succès !! ⚟ - ✅ │");
	printf("\n╘═══════════════════════════════════════════╛\e[0m\n");

	return 0;
}
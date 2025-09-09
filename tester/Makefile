.PHONY : all clean fclean re clear mandatory bonus norminette main bmain

NAME	=	../libftprintf.a

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC				:=	cc

CFLAGS			:=	-Wall -Wextra -Werror

RM				:=	rm -rf

MAKEFLAGS		+=	--no-print-directory

INCS			:=	HEADERS := $(shell find .. -name "*.h")

MF				:=	$(wildcard ../*akefile)

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : usage

main_compile:
	@$(MAKE) -C .. all

bonus_compile:
	@$(MAKE) -C .. bonus

usage:
	@echo "\e[1;32m🍃 Rules: 🍃\n   - 'main': test your program on the mandatory part\n   - 'bonus': test your program on the bonus part\e[0m"

rm:
	@$(RM) tester
	@echo "\e[1;35m🪷 - Test program deleted successfully - 🪷\e[0m"

main:
ifeq ($(MF),)
	@echo "\e[1;31m🍁 - Error: No makefile found in the previous directory - 🍁\e[0m"
	@exit
else
	@$(MAKE) rm
	@$(MAKE) main_compile
	@$(CC) -w mandatory.c $(NAME) -o tester
	@./tester
endif
	
bonus:
ifeq ($(MF),)
	@echo "\e[1;31m🍁 - Error: No makefile found in the previous directory - 🍁\e[0m"
	@exit
else
	@$(MAKE) rm
	@$(MAKE) bonus_compile
	@$(CC) -w bonus.c $(NAME) -o tester
	@./tester
endif
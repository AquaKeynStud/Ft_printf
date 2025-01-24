.PHONY : all clean fclean re clear mandatory bonus norminette main bmain

NAME = libftprintf.a

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
D_SRC = src/
D_BON = bonus/
D_INC = inc/
D_OBJ = .obj/
$(shell mkdir -p $(D_OBJ))

# file lists
LST_SRC =	utils2.c \
			utils.c \
			mandatory_printers.c \
			mandatory_handlers.c \

LST_MAN = 	mandatory_parser.c \

LST_BON =	bonus_main.c \
			bonus_parser.c \
			bonus_printers.c \
			bonus_printers_2.c \
			bonus_setter.c \
			bonus_utils.c \

LST_INC = 	ft_printf.h \

# files paths
SRC  =	$(addprefix $(D_SRC), $(LST_SRC))
MAN  =	$(addprefix $(D_SRC), $(LST_MAN))
BON  =	$(addprefix $(D_BON), $(LST_BON))
INC  = 	$(addprefix $(D_INC), $(LST_INC))
OBJ  = 	$(subst  $(D_SRC), $(D_OBJ), $(SRC:.c=.o))
MOBJ = 	$(subst  $(D_SRC), $(D_OBJ), $(MAN:.c=.o))
BOBJ = 	$(subst  $(D_BON), $(D_OBJ), $(BON:.c=.o))

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME) mandatory

$(NAME) : $(OBJ)

$(D_OBJ)%.o: $(D_SRC)%.c $(D_INC)ft_printf.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

$(D_OBJ)%.o: $(D_BON)%.c $(D_INC)ft_printf.h
	@mkdir -p $(D_OBJ)
	$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

bonus : $(D_OBJ).bonus

mandatory : clear $(MOBJ) $(LIBFT)
	@$(MAKE) $(NAME)
	@$(RM) $(D_OBJ)main.o
	@ar rcs $(NAME) $(OBJ) $(MOBJ)
	@echo "\e[0;32mArchive créée avec succès ! 🧬\e[0m"

$(D_OBJ).bonus : clear $(BOBJ) $(LIBFT)
	@$(MAKE) $(NAME)
	@$(RM) $(D_OBJ)mandatory_parser.o
	@ar rcs $(NAME) $(OBJ) $(BOBJ)
	@touch $(D_OBJ).bonus
	@echo "\e[0;32mArchive créée avec succès ! 🧬\e[0m"

clear:
	$(RM) $(NAME)

clean :
	$(RM) $(D_OBJ)
	@echo "\e[0;36mTout est nickel 🧹\e[0m"

fclean :
	$(MAKE) clean
	$(RM) $(NAME) mandatory_tester bonus_tester .bonus
	@echo "\e[0;34mJ'ai tout nettoyé :D 🧼\e[0m"

re :
	$(MAKE) fclean
	$(MAKE) all
	@echo "\e[0;32mArchive recréée avec succès ! 🫡\e[0m"

norminette :
	norminette -R CheckForbiddenSourceHeader $(D_SRC) $(D_BON) $(D_INC)

main : $(NAME)
	@$(CC) -w -I$(D_INC) main.c $(NAME) -o mandatory_tester
	@./mandatory_tester
	
bmain : $(NAME)
	@$(CC) -w -I$(D_INC) main_bonus.c $(NAME) -o bonus_tester
	@./bonus_tester
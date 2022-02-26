NAME = push_swap
NAME_BONUS = checker

OBJDIR = objs/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g #-fsanitize=address

FILES = main.c\
		utils.c\
		utils2.c\
		parse_arguments.c\
		check_arguments.c\
		norminette.c\
		util_bonus.c\
		lists.c\
		array_to_list.c\
		rules.c\
		rules2.c\
		rules3.c\
		sort3.c\
		sort5.c\
		sort100.c\
		sort500.c\

FILES_BONUS = bonus.c\
			  util_bonus.c\
			  rules.c\
			  rules2.c\
			  rules3.c\
			  utils2.c\
			  norminette.c\
			  utils.c\
			  parse_arguments.c\
			  array_to_list.c\
			  check_arguments.c\
			  lists.c\
			  gnl.c\
			  gnl_utils.c\
			  execute_commands_bonus.c\
			  get_commands.c\


VPATH = srcs/\
		srcs/utils/\
		srcs/parser/\
		srcs/lists/\
		srcs/rules/\
		srcs/sort/\
		srcs/bonus/\
		srcs/bonus/gnl\

HEADERS = includes/push_swap.h\
		  includes/checker.h\
		  includes/gnl.h\

FILES_O = $(addprefix objs/, $(notdir $(FILES)))
FILES_O_BONUS = $(addprefix objs/, $(notdir $(FILES_BONUS)))

OBJS = $(FILES_O:.c=.o)
OBJS_BONUS = $(FILES_O_BONUS:.c=.o)

NB = $(words $(FILES))
INDEX = 0

objs/%.o : %.c Makefile $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval PERCENT=$(shell expr $(INDEX) '*' 100 / $(NB)))
	@$(eval PROGRESS=$(shell expr $(INDEX) '*' 30 / $(NB)))
	@printf "\r\033[38;5;87mMAKE PUSH SWAP %2d%%\033[0m \033[48;5;32m%*s\033[0m %s\033[K" $(PERCENT) $(PROGRESS) "" $(notdir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

all: $(OBJDIR) $(NAME)

bonus: $(OBJDIR) $(NAME_BONUS)

$(OBJDIR):
	@mkdir objs/

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "\r\033[38;5;82mPUSH SWAP DONE\033[0m\033[K\n"

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)
	@printf "\r\033[38;5;82mCHECKER DONE\033[0m\033[K\n"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@rm -rf $(OBJDIR)
	@printf "\033[38;5;85mCLEAN\033[0m\n"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@printf "\033[38;5;84mFULL CLEAN\033[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re

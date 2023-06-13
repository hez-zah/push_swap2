SRC_FILE = mandatory/push_swap.c mandatory/creat_stak.c mandatory/cheak_err.c  mandatory/rotate.c \
		 mandatory/LIS.c mandatory/rrotate.c mandatory/pucher.c mandatory/swap.c mandatory/push.c \
		mandatory/indx_lst.c mandatory/broth_to_B.c mandatory/nbr_move.c mandatory/class.c mandatory/min_push_swap.c mandatory/free_stack.c

SRC_FILE_BONUS = bonus/checker.c bonus/g_n_l/get_next_line.c bonus/g_n_l/get_next_line_utils.c \
				bonus/lst.c bonus/cheak_err.c bonus/move1.c bonus/move2.c bonus/cheak_err_aid.c

NAME = push_swap
NAME_BONUS = checker
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_BONUS = $(SRC_FILE_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = push_swap.h checker.h
cc = gcc
RM = rm -rf

PURPLE = \033[0;35m
BLUE = \033[0;34m
RED = \033[0;31m

LIBTF_PATH = ./libft
LIBFT = $(LIBTF_PATH)/libft.a

all : $(NAME)

%.o:%.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(MAKE) -C $(LIBTF_PATH)
	$(cc) $(CFLAGS) $(OBJ_FILE) -o $(NAME) $(LIBFT)
	@echo "$(BLUE)tout est MAKE"

bonus : $(OBJ_FILE_BONUS)
	@$(MAKE) -C $(LIBTF_PATH)
	$(cc) $(CFLAGS) $(OBJ_FILE_BONUS) -o $(NAME_BONUS) $(LIBFT)
	@echo "$(PURPLE)tout est MAKE bounus"

clean :
	$(RM) $(OBJ_FILE) $(OBJ_FILE_BONUS)
	@${MAKE} -C $(LIBTF_PATH) clean
	@echo "$(RED) tout est clear"

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@${MAKE} -C $(LIBTF_PATH) fclean

re : fclean all
re_bonus : fclean bonus

SRC_FILE =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_strlcat.c\
ft_strchr.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
ft_strmapi.c ft_itoa.c ft_split.c ft_memmove.c ft_strrchr.c ft_strncmp.c ft_strtrim.c \
ft_bzero.c ft_atoi.c ft_strncmp.c  ft_substr.c ft_strjoin.c ft_strdup.c ft_calloc.c ft_strnstr.c \
ft_memcmp.c ft_memchr.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_memcpy.c ft_strlcpy.c ft_striteri.c ft_lstnew.c

SRC_FILE_BONUS = ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c
NAME = libft.a
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_BONUS = $(SRC_FILE_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h

all : $(NAME)

$(NAME) : $(OBJ_FILE) 
	@ar rc $(NAME) $(OBJ_FILE)
bonus: $(OBJ_FILE) $(OBJ_FILE_BONUS)
	@ar rc $(NAME) $(OBJ_FILE) $(OBJ_FILE_BONUS)

%.o:%.c $(HEADER)
	@cc $(CFLAGS) -c $< -o $@
clean :
	@rm -f $(OBJ_FILE) $(OBJ_FILE_BONUS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
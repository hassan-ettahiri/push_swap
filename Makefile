CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
NAME = push_swap
CHECHER = checker
SRC = 	push_swap.c rules1.c rules2.c ft_atoi.c ft_isdigit.c ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstnew.c ft_strlen.c ft_strncmp.c ft_split.c ft_lstclear.c ft_lstsize.c \
	sort1.c sort2.c sort3.c sort4.c sort5.c sort6.c sort7.c 

SRC_BONUS = checker_bonus/checker.c rules1.c rules2.c ft_atoi.c ft_isdigit.c ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstnew.c ft_strncmp.c ft_split.c ft_lstclear.c ft_lstsize.c \
	./checker_bonus/checker_utils_1.c ./checker_bonus/checker_utils_2.c\
	./checker_bonus/get_data/get_next_line.c ./checker_bonus/get_data/get_next_line_utils.c 

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	cc ${CFLAGS} $(OBJS) -o $(NAME)

bonus: $(OBJS_BONUS) ./checker_bonus/checker.h
	cc ${CFLAGS} $(OBJS_BONUS) -o $(CHECHER)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(CHECHER)

re: fclean all

#1 : rr
#2 : rrr
#3 : ra && rrb
#4 : rra && rb

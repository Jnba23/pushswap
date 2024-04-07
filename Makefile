#-*-Makefile-*-

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCM =  ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_split.c ft_strlcpy.c instructions.c instructions1.c \
		push_swap_utils.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c push_swap_utils6.c push_swap_utils7.c push_swap_utils8.c \
		push_swap.c
SRCB = ./bonus/checker_bonus_utils.c ./bonus/checker_bonus_utils1.c ./bonus/checker_bonus.c ./bonus/ft_strlcpy_bonus.c ./bonus/gnl/get_next_line_utils.c ./bonus/gnl/get_next_line.c \
		./bonus/instructions_bonus.c ./bonus/instructions1_bonus.c ./bonus/instructions.c ./bonus/instructions1.c \
		./bonus/ft_atoi_bonus.c ./bonus/ft_lstadd_front_bonus.c ./bonus/ft_lstadd_back_bonus.c ./bonus/ft_lstlast_bonus.c ./bonus/ft_lstnew_bonus.c ./bonus/ft_split_bonus.c \
		./bonus/push_swap_utils_bonus.c ./bonus/push_swap_utils2_bonus.c ./bonus/push_swap_utils3_bonus.c ./bonus/push_swap_utils4_bonus.c ./bonus/push_swap_utils5_bonus.c \
		./bonus/push_swap_utils6_bonus.c ./bonus/push_swap_utils7_bonus.c ./bonus/push_swap_utils8_bonus.c
OBJM = $(SRCM:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)

BONUS = checker
NAME = push_swap
HEADER_BONUS = ./bonus/pswap_bonus.h ./bonus/gnl/get_next_line.h
HEADER = pswap.h

all: $(NAME)
bonus: $(BONUS)

#object files for the push_swap executable : 
$(NAME): $(OBJM)
	cc $(CFLAGS) $^ -o $@ 
$(BONUS): $(OBJB)
	cc $(CFLAGS) $^ -o $@

$(OBJM):%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

#object files for checker executable :

$(OBJB): %.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJM) $(OBJB)
fclean: clean
	rm -f $(NAME) $(BONUS)
re: fclean all 

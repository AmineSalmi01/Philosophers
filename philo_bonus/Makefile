NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
RM = rm -rf

SRC = check_args_bonus.c ft_atoi_bonus.c philo_bonus.c init_structs_bonus.c \
	philo_utils_bonus.c philo_actions_bonus.c getters_bonus.c create_process.c
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) Philosophers_bonus.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c Philosophers_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
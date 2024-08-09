NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = check_args.c ft_atoi.c philo.c getters.c philo_actions.c create_threads.c \
	init_structs.c philo_utils.c
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) Philosophers.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c Philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
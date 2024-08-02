NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
RM = rm -rf

SRC = $(wildcard *.c)
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
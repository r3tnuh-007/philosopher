NAME = philos

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = ./philo/includes/philo.h\
		 ./philo/includes/utils.h

SRCS =	./philo/utils/data_init.c\
		./philo/utils/dinner_start.c\
		./philo/utils/error_exit.c\
		./philo/utils/getters_and_setters.c\
		./philo/utils/gettime.c\
		./philo/utils/parse_input.c\
		./philo/utils/precise_usleep.c\
		./philo/utils/safe_malloc.c\
		./philo/utils/safe_mutex_handle.c\
		./philo/utils/safe_thread_handle.c\
		./philo/utils/wait_all_threads.c\
		./philo/utils/write_status.c\
		./philo/main.c\

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

bonus: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -I $(HEADERS) -o $(NAME)

.PHONY: all clean fclean re bonus

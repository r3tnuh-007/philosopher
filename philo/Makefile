NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = ./includes/philo.h\
		 ./includes/utils.h

SRCS =	./utils/data_init.c\
		./utils/dinner_start.c\
		./utils/error_exit.c\
		./utils/getters_and_setters.c\
		./utils/gettime.c\
		./utils/parse_input.c\
		./utils/precise_usleep.c\
		./utils/safe_malloc.c\
		./utils/safe_mutex_handle.c\
		./utils/safe_thread_handle.c\
		./utils/wait_all_threads.c\
		./utils/write_status.c\
		./utils/monitor.c\
		./utils/clean.c\
		./main.c\

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

bonus: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

.PHONY: all clean fclean re bonus

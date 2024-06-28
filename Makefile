CC = gcc
CFLAGS = -Wall -Werror -Wextra
MFLAGS = -Lmlx_linux -lmlx_Linux -lX11 -lXext
LFLAGS = -Llibft -lft -Lprintf -lftprintf
CFILES = main.c\
		fractal.c\
		utils.c\
		render.c

SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR),$(CFILES))

HEADER = inc/fractol.h
NAME = fractol
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

all : library $(NAME) 

$(NAME) : $(SRC_FILES) $(HEADER) Makefile 
	$(CC) $(CFLAGS) $(SRC_FILES)  $(HEADER) $(MFLAGS) $(LFLAGS)  -g -o $(NAME)

library :
	@make -C libft
	@make -C printf
	@make -C mlx_linux

clean :
	@make clean -C printf
	@make clean -C libft
	@make clean -C libft

fclean :
	@make fclean -C printf
	@make fclean -C libft
	@make clean -C mlx_linux
	rm $(NAME)

re : fclean all

NAME = push_swap

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directorio
OBJ_DIR = obj/

# Obtener los .c
SRCS = $(wildcard *.c)

# Obtener los .o
OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

# Reglas
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpieza de archivos
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Indica que estas reglas no son archivos
.PHONY: all clean fclean re

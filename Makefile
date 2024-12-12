NAME = push_swap
BONUS_NAME = checker

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directorio
OBJ_DIR = obj/
BONUS_DIR = bonus/
SRC_DIR = src/
BONUS_OBJ_DIR = bonus_obj/

# Obtener los .c
SRCS = $(wildcard $(SRC_DIR)*.c)

BONUS_SRC = $(wildcard $(BONUS_DIR)*.c)

# Obtener los .o
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

BONUS_OBJS = $(patsubst $(BONUS_DIR)%.c, $(BONUS_OBJ_DIR)%.o, $(BONUS_SRC))

# Reglas principales
all: $(NAME)

bonus: $(BONUS_NAME)

# Reglas para push_swap

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas para el bonus
$(BONUS_NAME): $(BONUS_OBJ_DIR) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS)

$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorios
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

# Limpieza de archivos
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

# Indica que estas reglas no son archivos
.PHONY: all clean fclean re bonus

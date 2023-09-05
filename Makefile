SRV_NAME	= server
CLT_NAME	= client

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC			=	-I ./libft/\

SRC_PATH	=	src/
SRV_SRC		=	server.c
CLT_SRC		=	client.c

SRV_SRCS	= $(addprefix $(SRC_PATH), $(SRV_SRC))
CLT_SRCS	= $(addprefix $(SRC_PATH), $(CLT_SRC))


OBJ_PATH	= obj/
SRV_OBJ		= $(SRV_SRC:.c=.o)
CLT_OBJ 	= $(CLT_SRC:.c=.o)

SRV_OBJS	= $(addprefix $(OBJ_PATH), $(SRV_OBJ))
CLT_OBJS	= $(addprefix $(OBJ_PATH), $(CLT_OBJ))


all: $(SRV_NAME) $(CLT_NAME)

$(SRV_NAME): $(SRV_SRCS)
$(CLT_NAME): $(CLT_SRCS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(SRV_NAME): $(SRV_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(SRV_NAME) $(SRV_OBJS) $(LIBFT) $(INC)
	@echo "$(SRV_NAME) ready"

$(CLT_NAME): $(CLT_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CLT_NAME) $(CLT_OBJS) $(LIBFT) $(INC)
	@echo "$(CLT_NAME) ready"

bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 13:26:19 by chruhin           #+#    #+#              #
#    Updated: 2024/05/26 07:56:43 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME			=		gnl

SRC_DIR			=		src
OBJ_DIR			=		obj
INC_DIR			=		inc

DIRS			=		utils main
SRCS			=		$(foreach dir,$(DIRS),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))
OBJS			=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS			=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRCS))
INCS			=		$(addprefix -I, $(INC_DIR))

CFLAGS			=		-Wall -Wextra -MMD -MP -Werror
RM				=		rm -rf

.PHONY:					all clean fclean re
all:					$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
						@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):				$(OBJS)
						@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
						@printf "${GRN}Compiled successfuly $(RST) $(PIN)./$(NAME) ${RST}\n"

clean:
						@$(RM) $(OBJ_DIR)
						@printf "${RED}"'Deleted Object Files'"${RST}\n"

fclean:					clean
						@$(RM) $(NAME)
						@printf "${RED}"'and the Executable'"${RST}\n"

re:						fclean all

-include $(DEPS)

RED			=			\e[1;31m
GRN			=			\e[1;32m
PIN			=			\e[1;35m
RST			=			\e[0m

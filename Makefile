# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 13:26:19 by chruhin           #+#    #+#              #
#    Updated: 2024/03/05 14:05:05 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME				=		gnl

# Directories
SRC_DIR				=		src
OBJ_DIR				=		obj
INC_DIR				=		inc

# Source files
DIRS				=		utils main
SRCS				=		$(foreach dir,$(DIRS),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))

# Object files
OBJS				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Header files
INCS				=		$(addprefix -I, $(INC_DIR))

# Compiler flags
CFLAGS				=		-Wall -Wextra -Werror

# Cleanup
RM					=		rm -rf

# No exceptions
.PHONY:						all clean fclean re

# Targets
all:						$(OBJ_DIR) $(NAME)

# Create a Dir for obj
$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)
# Compiling obj
$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Compiling exec
$(NAME): 					$(OBJS)
							@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
							@printf "${GRN}"'Compiled successfuly'"${RST}\n"

# Remove object files
clean:
							@$(RM) $(OBJ_DIR)
							@printf "${RED}"'Deleted Object Files'"${RST}\n"
# Remove obj & exec files
fclean:						clean
							@$(RM) $(NAME)
							@printf "${RED}"'and the Executable File'"${RST}\n"
# remove all & recompile
re:							fclean all

# color codes
GRN					=		\e[1;32m
RED					=		\e[1;31m
RST					=		\e[1;0m

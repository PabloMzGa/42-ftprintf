# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 14:34:30 by pabmart2          #+#    #+#              #
#    Updated: 2025/09/10 19:33:20 by pabmart2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fno-inline
LDFLAGS = -lm
BUILD_DIR = .

OBJ_DIR = build/obj

NAME = libftprintf.a
AR = ar
ARFLAGS = rcs

HEADERS = \
	include/ft_printf.h \

SRC = \
	src/check_printer.c \
	src/ft_printf.c \
	src/libft/ft_bzero.c \
	src/libft/ft_calloc.c \
	src/libft/ft_free.c \
	src/libft/ft_itoa.c \
	src/libft/ft_memset.c \
	src/libft/ft_putchar_fd.c \
	src/libft/ft_putstr_fd.c \
	src/libft/ft_strlen.c \
	src/libft/ft_uintptrtob.c \
	src/libft/ft_uitoa.c \
	src/libft/ft_uitob.c \
	src/printers/c_printer.c \
	src/printers/di_printer.c \
	src/printers/p_printer.c \
	src/printers/prct_printer.c \
	src/printers/s_printer.c \
	src/printers/u_printer.c \
	src/printers/x_low_printer.c \
	src/printers/x_up_printer.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


PRINTF_INCLUDES = \
	-Iinclude \

all: $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(NAME)

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "\033[31mObject files removed\033[0m"

fclean: clean
	@rm -f $(BUILD_DIR)/$(NAME)
	@rm -f $(BONUS_BUILD_DIR)/$(BONUS_NAME)
	@echo "\033[31m$(NAME) removed\033[0m"

re: fclean
	$(MAKE) all


$(NAME): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	@$(AR) $(ARFLAGS) $(BUILD_DIR)/$(NAME) $(OBJ)
	@echo "\033[32m\n¡$(NAME) compiled! \
	ᕦ(\033[36m⌐■\033[32m_\033[36m■\033[32m)ᕤ\n"

$(OBJ) : $(OBJ_DIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(PRINTF_INCLUDES) -c $< -o $@
	@echo "\033[34mCompiling: \033[0m$<"


#################### BONUS #####################

BONUS_BUILD_DIR = .
BONUS_OBJ_DIR = build_bonus/obj
BONUS_NAME = libftprintf.a

BONUS_HEADERS = \
	bonus/include_bonus/ft_printf_bonus.h \

BONUS_SRC = \
	bonus/src_bonus/check_printer_bonus.c \
	bonus/src_bonus/ft_printf_bonus.c \
	bonus/src_bonus/parser_bonus.c \
	bonus/src_bonus/libft/ft_atoi_bonus.c \
	bonus/src_bonus/libft/ft_bzero_bonus.c \
	bonus/src_bonus/libft/ft_calloc_bonus.c \
	bonus/src_bonus/libft/ft_free_bonus.c \
	bonus/src_bonus/libft/ft_itoa_bonus.c \
	bonus/src_bonus/libft/ft_isdigit_bonus.c \
	bonus/src_bonus/libft/ft_isspace_bonus.c \
	bonus/src_bonus/libft/ft_memset_bonus.c \
	bonus/src_bonus/libft/ft_memcpy_bonus.c \
	bonus/src_bonus/libft/ft_putchar_fd_bonus.c \
	bonus/src_bonus/libft/ft_putstr_fd_bonus.c \
	bonus/src_bonus/libft/ft_strchr_bonus.c \
	bonus/src_bonus/libft/ft_strdup_bonus.c \
	bonus/src_bonus/libft/ft_strjoin_bonus.c \
	bonus/src_bonus/libft/ft_strlcat_bonus.c \
	bonus/src_bonus/libft/ft_strlcpy_bonus.c \
	bonus/src_bonus/libft/ft_strlen_bonus.c \
	bonus/src_bonus/libft/ft_uintptrtob_bonus.c \
	bonus/src_bonus/libft/ft_uitoa_bonus.c \
	bonus/src_bonus/libft/ft_uitob_bonus.c \
	bonus/src_bonus/formaters/alternate_format_formatter_bonus.c \
	bonus/src_bonus/formaters/padding_formatter_bonus.c \
	bonus/src_bonus/formaters/padding_formatter_helpers_bonus.c \
	bonus/src_bonus/formaters/positive_space_formater_bonus.c \
	bonus/src_bonus/formaters/positive_symbol_formater_bonus.c \
	bonus/src_bonus/formaters/precission_formater_bonus.c \
	bonus/src_bonus/printers/c_printer_bonus.c \
	bonus/src_bonus/printers/di_printer_bonus.c \
	bonus/src_bonus/printers/p_printer_bonus.c \
	bonus/src_bonus/printers/prct_printer_bonus.c \
	bonus/src_bonus/printers/s_printer_bonus.c \
	bonus/src_bonus/printers/u_printer_bonus.c \
	bonus/src_bonus/printers/x_low_printer_bonus.c \
	bonus/src_bonus/printers/x_up_printer_bonus.c \

BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC:.c=.o))

BONUS_INCLUDES = \
	-Ibonus/include_bonus \

bonus: $(BONUS_OBJ)
	@mkdir -p $(BONUS_BUILD_DIR)
	@$(AR) $(ARFLAGS) $(BONUS_BUILD_DIR)/$(BONUS_NAME) $(BONUS_OBJ)
	@echo "\033[32m\n¡$(BONUS_NAME) compiled! \
	ᕦ(\033[36m⌐■\033[32m_\033[36m■\033[32m)ᕤ\n"

debug_bonus: CFLAGS += $(DEBUG_FLAGS)
debug_bonus: clean bonus

$(BONUS_OBJ): $(BONUS_OBJ_DIR)/%.o : %.c $(BONUS_HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@
	@echo "\033[34mCompiling: \033[0m$<"


################################################
.PHONY: all debug clean fclean re bonus debug_bonus

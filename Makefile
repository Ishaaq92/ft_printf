# Variables
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = print_args.c ft_printf.c
OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
HEADER = ft_printf.h
TEST = main.c

# Default Target
all: $(NAME)

# Build Static Library
$(NAME): $(OBJS)
	
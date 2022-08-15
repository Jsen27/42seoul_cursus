CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
SRCS = srcs
INCLUDES = includes
TARGET = libft.a
SOURCES = $(SRCS)/ft_putchar.c $(SRCS)/ft_swap.c $(SRCS)/ft_putstr.c $(SRCS)/ft_strlen.c $(SRCS)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)
all: $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCLUDES)
$(TARGET): $(OBJECTS)
	ar cr $@ $(OBJECTS)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(TARGET)
re: fclean all

MAKE = make -C
NAME = fdf
LIB = src/libft/
CFLAGS = -Wall -Wextra
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
        src/main.c \

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(CFLAGS) -I includes/ -o $(NAME) $(CFILES)
	@echo "FDF: Successfull compilation"
	

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS) printf:.o
	@echo "FDF: Removed .o files"

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)
	@echo "FDF: Removed exacutable & .o files"

re: fclean all

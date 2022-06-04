NAME =	minishell
CC=gcc
CFLAGS=	-Wall -Wextra -Werror -g3

SRCS=	minishell.c \


RM= rm -f
OBJ= $(SRCS:.c=.o)

INCS= -I includes -I my_lib/includes
MY_LIB= my_lib/lib_my.a

all : $(MY_LIB) $(NAME)


$(NAME) :  $(OBJ) 
	$(CC) $(CFLAGS) -L my_lib $(OBJ) -o $@ $(INCS) -l_my -lreadline

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

my_lib/lib_my.a:
	make -C my_lib all

clean :	
	$(RM) $(OBJ)
	make -C my_lib clean

fclean : clean
	$(RM) $(NAME)
	$(RM) my_lib/lib_my.a

re : 	
		make fclean
		make all

.PHONY : all clean fclean re bonus

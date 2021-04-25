C_YELLOWB=\033[1;33m
C_BLUEB=\033[1;34m
C_REDB=\033[0;91m
C_WHITE=\033[0;97m
C_WHITEB=\033[1;97m
C_RESET=\033[0;39m

SRCS	= ./src/ft_others.c ./src/ft_strxcpy.c ./src/ft_file.c ./src/ft_strings_line.c ./src/ft_num2words.c ./src/ft_str.c ./src/ft_split.c ./src/main.c ./src/ft_dictionary.c ./src/ft_file_io.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= rush-02
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

run :
	./${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette */*.[ch]

find_sources :
	find src -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '

re : fclean all

test : re
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 42$(C_RESET)" ;
	@./${NAME} 42 | cat -e || true ;
	@##
	@echo "\n"
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 0$(C_RESET)" ;
	@./${NAME} 0 | cat -e || true ;
	@##
	@echo "\n"
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 10.4$(C_RESET)" ;
	@./${NAME} 10.4 | cat -e || true ;
	@##
	@echo "\n"
		@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 10.4$(C_RESET)" ;
	@./${NAME} 12345678 | cat -e || true ;
	@##
	@echo "\n"

testnocat : re
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 42$(C_RESET)" ;
	@./${NAME} 42 || true ;
	@##
	@echo "\n"
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 0$(C_RESET)" ;
	@./${NAME} 0 || true ;
	@##
	@echo "\n"
	@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 10.4$(C_RESET)" ;
	@./${NAME} 10.4 || true ;
	@##
	@echo "\n"
		@echo "[$(C_YELLOWB)TESTING$(C_RESET)] $(C_WHITEB)Number: 10.4$(C_RESET)" ;
	@./${NAME} 1234 || true ;
	@##
	@echo "\n"


.PHONY: all clean fclean re .c.o test
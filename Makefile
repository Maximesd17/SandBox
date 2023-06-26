##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_DIR 	= 	src
GAME_DIR 	= 	src/Game
SCENES_DIR 	= 	src/Scenes
COMPONENTS_DIR 	= 	src/Component

MAIN		=	${SRC_DIR}/main.cpp	\

SRC			=	${SRC_DIR}/SandBox.cpp	\
				${SRC_DIR}/State.cpp	\
				${GAME_DIR}/Game.cpp	\
				${GAME_DIR}/MapGenerator.cpp	\
				${SCENES_DIR}/AScene.cpp	\
				${SCENES_DIR}/SGame.cpp	\
				${SCENES_DIR}/SMenu.cpp	\
				${SCENES_DIR}/SMainMenu.cpp	\
				${SCENES_DIR}/SSettingsMenu.cpp	\
				${SCENES_DIR}/SMainGame.cpp	\
				${COMPONENTS_DIR}/Button.cpp	\
				${COMPONENTS_DIR}/Player.cpp	\

TESTS_DIR	=	tests
TESTS_SRC	=	${TESTS_DIR}/Game/tests_MapGenerator.cpp

INCLUDES	=	-iquote ./include
INCLUDES	+=	-iquote ./include/Game
INCLUDES	+=	-iquote ./include/Scenes
INCLUDES	+=	-iquote ./include/Component

CXX 		= 	g++

CXXFLAGS 	= 	${INCLUDES} -W -Wall -Wextra -std=c++11

LDLIBS 		+=	-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window

NAME 		=	MySandBox

MAIN_OBJ	=	${MAIN:.cpp=.o}
OBJ			=	${SRC:.cpp=.o}

all: ${NAME}

core:	${NAME}

${NAME}: ${MAIN_OBJ} ${OBJ}
	${CXX} -o ${NAME} ${MAIN_OBJ} ${OBJ} ${LDFLAGS} ${LDLIBS}

debug: 	CXXFLAGS += -g3
debug:	re

clean:
	${RM} ${OBJ}

fclean: clean
	$(RM) $(NAME)

re: fclean all

#Can add "--coverage" if we want them in future for gcovr :)
run_tests: ${OBJ}
	${CXX} ${OBJ} ${TESTS_SRC} ${LDFLAGS} ${LDLIBS} ${INCLUDES} -lcriterion -o unit_tests
	-./unit_tests --verbose=0
	${RM} *.gcno
	${RM} *.gcda

.PHONY: all debug clean fclean re

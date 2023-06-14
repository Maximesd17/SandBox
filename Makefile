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

SRC			=	${SRC_DIR}/main.cpp
SRC			+=	${SRC_DIR}/SandBox.cpp
SRC			+=	${SRC_DIR}/State.cpp
SRC			+=	${GAME_DIR}/Game.cpp
SRC			+=	${SCENES_DIR}/AScene.cpp
SRC			+=	${SCENES_DIR}/SGame.cpp
SRC			+=	${SCENES_DIR}/SMenu.cpp
SRC			+=	${SCENES_DIR}/SMainMenu.cpp
SRC			+=	${SCENES_DIR}/SSettingsMenu.cpp
SRC			+=	${SCENES_DIR}/SMainGame.cpp
SRC			+=	${COMPONENTS_DIR}/Button.cpp
SRC			+=	${COMPONENTS_DIR}/Player.cpp

INCLUDES	=	-iquote ./include
INCLUDES	+=	-iquote ./include/Game
INCLUDES	+=	-iquote ./include/Scenes
INCLUDES	+=	-iquote ./include/Component

CXX 		= 	g++

CXXFLAGS 	= 	${INCLUDES} -W -Wall -Wextra -std=c++11

LDLIBS 		+=	-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window

NAME 		=	MySandBox

OBJ			=	${SRC:.cpp=.o}

all: ${NAME}

core:	${NAME}

${NAME}: ${OBJ}
	${CXX} -o ${NAME} ${OBJ} ${LDFLAGS} ${LDLIBS}

debug: 	CXXFLAGS += -g3
debug:	re

clean:
	${RM} ${OBJ}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re

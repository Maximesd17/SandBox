
all: compile run

compile:
	make -C game/

recompile:
	make re -C game/

run: compile
	make run -C game/

re: recompile run
COMPILER = g++

OBJ_NAME = main

OBJS = app/objects/**.cpp main.cpp

LIBRARIES = -lSDL -lSDL_image

DEBUGGER = -g

all : $(OBJS)
	$(COMPILER) -o $(OBJ_NAME) $(OBJS) $(LIBRARIES)
	$(COMPILER) $(DEBUGGER) $(OBJS) $(LIBRARIES)

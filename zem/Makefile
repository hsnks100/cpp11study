#OBJS specifies which files to compile as part of the project
OBJS = chap11.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w : watch all warnings
COMPILER_FLAGS = -w -std=c++11 -lpthread -lm

#OBJ_NAME specifies the name of our executable
OBJ_NAME = output.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)

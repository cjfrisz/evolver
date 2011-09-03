##################################################
# Makefile for Evolver project
# Written by Chris Frisz
# Created 15 Aug 2011
# Last updated 2 Sept 2011
##################################################

#----------VARIABLES----------#

# Path variables
PROJ_PATH=.
SRC_PATH=$(PROJ_PATH)
BASE_PATH=$(SRC_PATH)
GL_PATH=$(SRC_PATH)
BIN_PATH=$(PROJ_PATH)

# Compiler variables
CXX=g++
DEBUG_FLAGS=-g
CXX_FLAGS=$(DEBUG_FLAGS)
GL_FLAGS=-lGLU -lGL
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
O_FLAGS=$(CXX_FLAGS) -c
TARGET_FLAGS=$(SFML_FLAGS) $(GL_FLAGS) $(CXX_FLAGS) -o

# Source/target file variables
TARGET=$(BIN_PATH)/evolver
MAIN=evolver.cpp
BASE_FILES=Hitbox.o \
	Actor.o \
	Config.o \
	Controller.o
GL_FILES=ActorGL.o
O_FILES=$(BASE_FILES) $(GL_FILES)

# Delete utility and target variables
RM=rm
RM_FLAGS=-f
EXCESS_FILES=*~ core.*


#----------VPATH DIRECTIVES----------#

# Base files
vpath %.cpp $(BASE_PATH)
vpath %.h $(BASE_PATH)

# OpenGL wrapper files
vpath %.cpp $(GL_PATH)
vpath %.h $(GL_PATH)


#----------RULES----------#

# Build everything
all : $(TARGET)

# Build and run
run : all
	$(TARGET)

# Target
$(TARGET) : $(MAIN) $(O_FILES)
	$(CXX) $(TARGET_FLAGS) $(TARGET) $(MAIN) $(O_FILES)

# Object files
%.o : %.cpp %.h
	$(CXX) $(O_FLAGS) $<

# Remove excess and object files for compiling target
clean : 
	$(RM) $(RM_FLAGS) $(EXCESS_FILES) $(O_FILES)

# Remove all build files in addition to clean directives
scrub : clean
	$(RM) $(RM_FLAGS) $(TARGET)
##################################################
# Makefile for Evolver project
# Written by Chris Frisz
# Created 15 Aug 2011
# Last updated 15 Aug 2011
##################################################

#----------VARIABLES----------#

# Path variables
PROJ_PATH=.
SRC_PATH=$(PROJ_PATH)
BASE_PATH=$(SRC_PROJ_PATH)
GL_PATH=$(SRC_PATH)
BIN_PATH=$(PROJ_PATH)

# Compiler variables
CXX=g++
DEBUG_FLAGS=-g
CXX_FLAGS=$(DEBUG_FLAGS) -o
GL_FLAGS=-lGLU -lGL
SDL_FLAGS=-lSDL
O_FLAGS=$(DEBUG_FLAGS) -c
TARGET_FLAGS=$(GL_FLAGS) $(SDL_FLAGS) $(CXX_FLAGS)

# Source/target file variables
TARGET=$(BIN_PATH)/evolver
MAIN=evolver.cpp
BASE_FILES=Coordinates.o \
	Hitbox.o \
	Character.o
GL_FILES=CharacterGL.o
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
	$(BIN_PATH)/$(TARGET)

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
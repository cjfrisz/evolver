##################################################
# Makefile for Evolver project
# Written by Chris Frisz
# Created 15 Aug 2011
# Last updated 23 Sept 2011
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
DEBUG_FLAGS=
CXX_FLAGS=$(DEBUG_FLAGS)
GL_FLAGS=-lGLU -lGL
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
O_FLAGS=$(CXX_FLAGS) -c
TARGET_FLAGS=$(SFML_FLAGS) $(GL_FLAGS) $(CXX_FLAGS) -o

# Source/target file variables
TARGET=$(BIN_PATH)/evolver
MAIN=evolverSF.cpp
BASE_CLASSES=ActorCommand \
	Actor \
	Clock \
	Command \
	Config \
	FallBehavior \
	JumpBehavior \
	JumpCommand \
	MoveBehavior \
	MoveDownCommand \
	MoveLeftCommand \
	MoveRightCommand \
	MoveUpCommand \
	NoFall \
	NoJump \
	NoMovement \
	Observer \
	TextFall \
	TextJump \
	TextMove \
	Timer \
	TimeStamp
GL_CLASSES=ActorGL
BASE_O_FILES=$(addsuffix .o, $(BASE_CLASSES))
GL_O_FILES=$(addsuffix .o, $(GL_CLASSES))
O_FILES=$(BASE_O_FILES) $(GL_O_FILES)

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

# Add debug information
debug : DEBUG_FLAGS=-g
debug : $(TARGET)

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
clobber : clean
	$(RM) $(RM_FLAGS) $(TARGET)
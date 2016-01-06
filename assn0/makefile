#########################################################
# File: makefile
# Author: Jason Goldfine-Middleton
# Description: Builds assignment 0 for CS 261.
#########################################################

# C Compiler
CXX = gcc

# Compile Flags
CXXFLAGS = -std=c99
CXXFLAGS += -Wall
CXXFLAGS += -pedantic
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# Source Files
SRC1 = main.c
SRC2 = 
SRCS = ${SRC1}

# Header Files
HEADER1 = 
HEADERS = ${HEADER1}

# Executables
PROG1 = main
PROGS = ${PROG1}

# Documents
DOC = jasongoldfinemiddleton.pdf

# Archive
ZIP = goldfinj_cs261_assn0.zip

# Extras
FILES  = cs261_assn0_output_flip.png
FILES += cs261_assn0_output_vs.png
FILES += cs261_assn0_source.png

#####################
### BUILD SECTION ###
#####################

all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOC} ${FILES}  makefile

clean: 
	rm -f ${PROGS} *.o *~


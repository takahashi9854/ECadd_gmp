#------------------------------------------------------
# Makefile for C/C++ Program
#------------------------------------------------------
# Target: ECadd.out or ECadd.exe
#------------------------------------------------------

TARGET=ECadd_gmp

#------------------------------------------------------
# Default Parameters
#------------------------------------------------------

CC=g++
RM=rm
OPT=
INC=
LIB=-lgmp -lgmpxx

#------------------------------------------------------
# Compile Option
#------------------------------------------------------

-include makefile.opt

#------------------------------------------------------
# Definition
#------------------------------------------------------

.SUFFIXES:.cpp .c .o .h

#---
# Source Files
#---

SRC=$(shell ls *.cpp)
HED=$(shell ls *.h)
OBJ=$(SRC:.cpp=.o)

#------------------------------------------------------
# rules
#------------------------------------------------------

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(OPT) -o $(TARGET) $(OBJ) $(LIB)

.c.o:
	$(CC) $(OPT) -c $< $(INC)
.cpp.o:
	$(CC) $(OPT) -c $< $(INC)

dep:
	$(CC) -MM -MG $(SRC) >makefile.depend

clean:
	$(RM) -f $(TARGET) $(TARGET).exe
	$(RM) -f *.o *.obj
	$(RM) -f *~ *.~*

tar:
	tar cvzf $(TARGET).tar.gz $(SRC) $(HED) makefile

#--------------------------------------------------

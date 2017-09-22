# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica1

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I. -std=c++11

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

#Macros carpetas
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) :
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/figura.cc  -o $(OBJ)/figura.o -I $(INC)
	$(CC) $(SRC)/practica1.cc  $(OBJ)/figura.o -o $(BIN)/practica1  $(CXXFLAGS) $(LDFLAGS) -I $(INC)

#
#
clean:
	rm -f $(OBJ)/*.o
	rm -f $(TARGETS)

#
#
redo:
	touch $(SRC)/*.cc
	make

#
#
superclean:
	rm -f $(OBJ)/*.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f $(OBJ)/*.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

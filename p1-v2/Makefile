# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica1

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -I/usr/include -I.
CXXFLAGS=  -g -I/usr/include -I. -std=c++11

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
#Para Apple
LDFLAGS= -framework OpenGL -framework GLUT -framework IOKit

# definicion del compilador
#
CC = g++

#macros
SRC = src
OBJ = obj
INC = include
LIB = lib
BIN = bin

# definicion de objetos
#
OBJECTS= $(OBJ)/practica1.o $(OBJ)/escena.o $(OBJ)/ejes.o $(OBJ)/figura.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/piramide.o
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)

$(OBJ)/practica1.o: $(OBJECTS)
	$(CC) $(SRC)/practica1.cc $(OBJ)/ejes.o  $(OBJ)/figura.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/piramide.o $(OBJ)/escena.o -o $(BIN)/practica1  $(CXXFLAGS) $(LDFLAGS) -I $(INC)

$(OBJ)/escena.o: $(SRC)/escena.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/escena.cc  -o $(OBJ)/escena.o -I $(INC)

$(OBJ)/ejes.o: $(SRC)/ejes.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/ejes.cc  -o $(OBJ)/ejes.o -I $(INC)

$(OBJ)/figura.o: $(SRC)/figura.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/figura.cc  -o $(OBJ)/figura.o -I $(INC)

$(OBJ)/cubo.o: $(SRC)/cubo.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/cubo.cc  -o $(OBJ)/cubo.o -I $(INC)

$(OBJ)/tetraedro.o: $(SRC)/tetraedro.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/tetraedro.cc  -o $(OBJ)/tetraedro.o -I $(INC)

$(OBJ)/piramide.o: $(SRC)/piramide.cc
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $(SRC)/piramide.cc  -o $(OBJ)/piramide.o -I $(INC)

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
	#rm *~
	rm -f $(TARGETS)
	rm $(BIN)/*

#
#
tgz: superclean
	tar -zcvf $(TARGETS).tgz *

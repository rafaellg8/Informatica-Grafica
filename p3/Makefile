# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#

CFLAGS=    -g -I/usr/include -I.
CXXFLAGS=  -g -I/usr/include -I. -std=c++11 -O3

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#

OS := $(shell uname)
ifeq ($(OS),Darwin) #usando mac osx usamos el framework GLUT
	LDFLAGS= -framework OpenGL -framework GLUT
else
	LDFLAGS=  -lGLU -lGL -lglut
endif

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
OBJECTS= $(OBJ)/practica.o $(OBJ)/escena.o $(OBJ)/ejes.o $(OBJ)/figura.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/piramide.o $(OBJ)/file_ply_stl.o $(OBJ)/ObjetoPLY.o $(OBJ)/Perfil.o
# orden que sera ejecutada por defecto
#
default : $(OBJ)/practica.o

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)

$(OBJ)/practica.o: $(OBJECTS)
	$(CC) -o $(BIN)/practica $(OBJ)/ejes.o  $(OBJ)/figura.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/piramide.o $(OBJ)/escena.o $(OBJ)/file_ply_stl.o $(OBJ)/ObjetoPLY.o $(OBJ)/Perfil.o $(SRC)/practica.cc $(CXXFLAGS) $(LDFLAGS) -I $(INC)

$(OBJ)/escena.o: $(SRC)/escena.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/escena.cc  -o $(OBJ)/escena.o -I $(INC)

$(OBJ)/ejes.o: $(SRC)/ejes.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/ejes.cc  -o $(OBJ)/ejes.o -I $(INC)

$(OBJ)/figura.o: $(SRC)/figura.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/figura.cc  -o $(OBJ)/figura.o -I $(INC)

$(OBJ)/cubo.o: $(SRC)/cubo.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/cubo.cc  -o $(OBJ)/cubo.o -I $(INC)

$(OBJ)/tetraedro.o: $(SRC)/tetraedro.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/tetraedro.cc  -o $(OBJ)/tetraedro.o -I $(INC)

$(OBJ)/piramide.o: $(SRC)/piramide.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/piramide.cc  -o $(OBJ)/piramide.o -I $(INC)

$(OBJ)/read_ply.o:
	$(CC) $(CXXFLAGS) -c $(SRC)/read_ply.cc  -o $(OBJ)/read_ply.o -I $(INC)

$(OBJ)/file_ply_stl.o:
	$(CC) $(CXXFLAGS) -c $(SRC)/file_ply_stl.cc  -o $(OBJ)/file_ply_stl.o -I $(INC)

$(OBJ)/ObjetoPLY.o:
	$(CC) $(CXXFLAGS) -c $(SRC)/ObjetoPLY.cc  -o $(OBJ)/ObjetoPLY.o -I $(INC)

$(OBJ)/Perfil.o: $(SRC)/Perfil.cc
	$(CC) $(CXXFLAGS) -c $(SRC)/Perfil.cc  -o $(OBJ)/Perfil.o -I $(INC)
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

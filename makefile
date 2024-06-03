CC = g++
CFLAGS = -std=c++11
CFLAGS_DEBUG = -std=c++11 -Wall -g
TARGET = prog

BUILD = ./build
SRC = ./src
INCLUDE = ./include

all: ${BUILD}/${TARGET}


${BUILD}/${TARGET}:  ${BUILD}/ataques.o ${BUILD}/combate.o ${BUILD}/entidade.o ${BUILD}/EscolhaClasse.o ${BUILD}/monstro.o ${BUILD}/Economia.o ${BUILD}/Campanha.o ${BUILD}/inventario.o ${BUILD}/Sorte.o ${BUILD}/personagem.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/ataques.o ${BUILD}/combate.o ${BUILD}/entidade.o ${BUILD}/EscolhaClasse.o ${BUILD}/monstro.o ${BUILD}/Economia.o ${BUILD}/Campanha.o ${BUILD}/inventario.o ${BUILD}/Sorte.o ${BUILD}/personagem.o ${BUILD}/main.o -o ${BUILD}/${TARGET}


${BUILD}/ataques.o: ${INCLUDE}/modulo1/ataques.hpp ${SRC}/modulo1/ataques.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -c ${SRC}/modulo1/ataques.cpp -o ${BUILD}/ataques.o

${BUILD}/combate.o: ${INCLUDE}/modulo1/combate.hpp ${INCLUDE}/modulo1/monstro.hpp ${INCLUDE}/modulo1/personagem.hpp ${INCLUDE}/modulo1/ataques.hpp ${SRC}/modulo1/combate.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -c ${SRC}/modulo1/combate.cpp -o ${BUILD}/combate.o

${BUILD}/entidade.o: ${INCLUDE}/modulo1/entidade.hpp ${SRC}/modulo1/entidade.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -c ${SRC}/modulo1/entidade.cpp -o ${BUILD}/entidade.o

${BUILD}/EscolhaClasse.o: ${INCLUDE}/modulo1/EscolhaClasse.hpp ${SRC}/modulo1/EscolhaClasse.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -c ${SRC}/modulo1/EscolhaClasse.cpp -o ${BUILD}/EscolhaClasse.o

${BUILD}/monstro.o: ${INCLUDE}/modulo1/monstro.hpp ${INCLUDE}/modulo1/entidade.hpp ${INCLUDE}/modulo1/ataques.hpp ${SRC}/modulo1/monstro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -c ${SRC}/modulo1/monstro.cpp -o ${BUILD}/monstro.o 

${BUILD}/personagem.o: ${INCLUDE}/modulo1/personagem.hpp ${INCLUDE}/modulo1/entidade.hpp ${INCLUDE}/modulo1/ataques.hpp ${SRC}/modulo1/personagem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -c ${SRC}/modulo1/personagem.cpp -o ${BUILD}/personagem.o 

${BUILD}/Campanha.o: ${INCLUDE}/modulo2/Campanha.hpp ${SRC}/modulo2/Campanha.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo2/ -c ${SRC}/modulo2/Campanha.cpp -o ${BUILD}/Campanha.o

${BUILD}/Economia.o: ${INCLUDE}/modulo2/Economia.hpp ${SRC}/modulo2/Economia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo2/ -c ${SRC}/modulo2/Economia.cpp -o ${BUILD}/Economia.o

${BUILD}/inventario.o: ${INCLUDE}/modulo2/inventario.hpp ${INCLUDE}/modulo2/Economia.hpp ${SRC}/modulo2/inventario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo2/ -c ${SRC}/modulo2/inventario.cpp -o ${BUILD}/inventario.o

${BUILD}/Sorte.o: ${INCLUDE}/modulo2/Sorte.hpp ${SRC}/modulo2/Sorte.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo2/ -c ${SRC}/modulo2/Sorte.cpp -o ${BUILD}/Sorte.o

${BUILD}/main.o: ${INCLUDE}/modulo1/ataques.hpp ${INCLUDE}/modulo1/combate.hpp ${INCLUDE}/modulo1/entidade.hpp ${INCLUDE}/modulo1/EscolhaClasse.hpp ${INCLUDE}/modulo1/monstro.hpp ${INCLUDE}/modulo1/personagem.hpp ${INCLUDE}/modulo2/Campanha.hpp ${INCLUDE}/modulo2/Economia.hpp ${INCLUDE}/modulo2/inventario.hpp ${INCLUDE}/modulo2/Sorte.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/modulo1/ -I ${INCLUDE}/modulo2/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

builder:
	if not exist build mkdir build

run:
	${BUILD}/${TARGET}

clean:
	del build\*.exe
	del build\*.o

test:
	g++ -std=c++11 -Wall -g test.cpp -o progTeste
	.\progTeste.exe

cleanTest:
	del progTeste.exe

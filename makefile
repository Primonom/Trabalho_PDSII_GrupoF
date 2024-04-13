CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/personagem.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/personagem.o  ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/personagem.o: ${INCLUDE}/personagem.hpp ${SRC}/personagem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/personagem.cpp -o ${BUILD}/personagem.o

${BUILD}/main.o: ${INCLUDE}/personagem.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o


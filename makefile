CXX = g++
CXXFLAGS = -std=c++0x -Wall -g
LDFLAGS = -lboost_date_time

OBJS = queue.o space.o actionSpace.o toolSpace.o doorSpace.o tool.o item.o hint.o menu.o board.o main.o

SRCS = queue.cpp space.cpp actionSpace.cpp toolSpace.cpp doorSpace.cpp tool.cpp item.cpp hint.cpp menu.cpp board.cpp main.cpp

HEADERS = queue.hpp space.hpp actionSpace.hpp toolSpace.hpp doorSpace.cpp tool.hpp item.hpp hint.hpp board.hpp menu.hpp

PirateEscape: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -g -o PirateEscape

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean :
	rm PirateEscape ${OBJS}

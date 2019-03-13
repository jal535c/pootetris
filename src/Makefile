SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))
INCLUDE := -I.
LIBS := -lpthread -lX11

all: main

main: $(OBJECTS)
	g++ -o $@ $^ $(LIBS)

%.o: %.cpp
	g++ -c $^ $(INCLUDE)

clean:
	rm *.o main

info:
	$(info $(SOURCES))
include ../../../../build.config

CFLAGS = $(DEFINES) $(INCLUDES)

CPPFILES = write_test_pgm.cpp

OBJ = $(CPPFILES:.cpp=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) -g -o write_test_pgm $(OBJ) -static-libgcc -static-libstdc++

.cpp.o:
	$(CC) $(CFLAGS) -c $(CPPFILES)

clean:
	rm -f $(OBJ)
	rm -f write_test_pgm

install:
	cp -f write_test_pgm /usr/local/ashin/.tools
	cp -f write_test_pgm $(AS_PKG_HOME)/tool
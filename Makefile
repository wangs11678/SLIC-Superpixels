CXXFLAGS = $(shell pkg-config --cflags opencv)
LDLIBS = $(shell pkg-config --libs opencv)

CC = g++

objects = segment.cpp slic.cpp slic.h

segment : $(objects)
	#$(CC) -o libsegment.so -shared -fPIC $(objects) $(CXXFLAGS) $(LDLIBS)
	$(CC) -o segment $(objects) $(CXXFLAGS) $(LDLIBS)
clean:
	/bin/rm -f segment *.o

clean-all: clean
	/bin/rm -f *~ 


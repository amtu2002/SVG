CXXFLAGS = -Wall

checkpack: checkpack.o Shape.o Domain.o Point.o
	$(CXX) -o $@ $^

clean:
	rm -f checkpack *.o
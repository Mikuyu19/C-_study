CXX = aarch64-linux-gnu-g++
a.out : main.o screen.o point.o color.o rect.o circle.o bitmap.o dir.o list.o
	$(CXX) $^ -o $@

clean:
	rm *.o -rf 
	rm a.out -rf

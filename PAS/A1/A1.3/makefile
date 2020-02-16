all: test

test: Collection_test.o Stress_ball_test.o Jeans_test.o
	c++ -std=c++11 Collection_test.o Stress_ball_test.o Jeans_test.o -o test

Collection_test.o: Collection_test.cpp Collection.h Jeans.h
	c++ -std=c++11 -c Collection_test.cpp

Stress_ball_test.o: Stress_ball_test.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball_test.cpp

Jeans_test.o: Jeans_test.cpp Jeans.h
	c++ -std=c++11 -c Jeans_test.cpp

clean:
	rm -f *.o test

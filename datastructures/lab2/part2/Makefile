centralcity: cccitizen.o metahuman.o human.o main.o
	g++ cccitizen.o metahuman.o human.o main.o -o centralcity

main.o: main.cpp
	g++ -c main.cpp

metahuman.o: metahuman.cpp metahuman.h
	g++ -c metahuman.cpp

human.o: human.cpp human.h
	g++ -c human.cpp

cccitizen.o: cccitizen.cpp cccitizen.h
	g++ -c cccitizen.cpp

clean:
	rm *.o
	rm centralcity

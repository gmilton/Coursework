CMP = g++ -Wall -std=c++11
CLASS = cell
CLASS2 = board
MAIN = main
EXEC = solveit

$(EXEC): $(CLASS).o $(CLASS2).o $(MAIN).o
	$(CMP) $(CLASS).o $(CLASS2).o $(MAIN).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -o $(CLASS2).o

clean:
	rm *.o
	rm $(EXEC)

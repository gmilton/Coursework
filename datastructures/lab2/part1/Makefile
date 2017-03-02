CMP = g++
CLASS = carddeck
MAIN = cardmain
EXEC = deck

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) $(CLASS).o $(MAIN).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

clean:
	rm *.o
	rm $(EXEC)

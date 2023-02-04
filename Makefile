run: SolverProgram.o example.csv
	./SolverProgram.o "example.csv"

SolverProgram.o : solver.c example.csv
	gcc -o SolverProgram.o solver.c #compile [[solver.c]] into file named [[SolverProgram.o]]

clean : 
	rm *.o

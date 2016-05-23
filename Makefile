all: knapsack_tabu

knapsack_tabu: solucion.o mochila.o objeto.o soluciones.o main.o
			g++ solucion.o main.o mochila.o objeto.o soluciones.o -g -o knapsack_tabu


solucion.o: solucion.cpp solucion.h
			g++ -Wall -g -c solucion.cpp

mochila.o : mochila.cpp mochila.h
		g++ -Wall -g -c mochila.cpp

objeto.o : objeto.cpp objeto.h
					g++ -Wall -g -c objeto.cpp

soluciones.o: soluciones.cpp soluciones.h
					g++ -Wall -g -c soluciones.cpp

main.o: main.cpp
		  g++ -Wall -g -c main.cpp

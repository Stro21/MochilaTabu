all: knapsack_tabu

knapsack_tabu: iteracion.o mochila.o objeto.o main.o
			g++ iteracion.o main.o mochila.o objeto.o -g -o knapsack_tabu


iteracion.o: iteracion.cpp iteracion.h
			g++ -Wall -g -c iteracion.cpp

mochila.o : mochila.cpp mochila.h
		g++ -Wall -g -c mochila.cpp

objeto.o : objeto.cpp objeto.h
					g++ -Wall -g -c objeto.cpp

main.o: main.cpp
		  g++ -Wall -g -c main.cpp

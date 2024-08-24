.default: all

all: main.exe

clean:
	rm -rf main.exe *.o *.dSYM

main.exe: main.o Patient.o PatientRegister.o WaitingList.o 
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $<
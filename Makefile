Mango: Mango.o Mode.o Session.o Messages.o
	g++ -Wno-deprecated -std=c++17 -I include -o Mango Mango.o Mode.o Session.o Messages.o

Mode.o:
	g++ -Wno-deprecated -std=c++17 -I include -c Mode.h Mode.cpp

Mango.o:
	g++ -Wno-deprecated -std=c++17 -I include -c Mango.cpp

Session.o:
	g++ -Wno-deprecated -std=c++17 -I include -c Session.h Session.cpp

Messages.o:
	g++ -Wno-deprecated -std=c++17 -c Messages.h Messages.cpp

clean:
		rm Mango.o Mode.o Mango Session.o

debug:
	g++  Mango.cpp Mode.h Mode.cpp Session.h Session.cpp Messages.h Messages.cpp -g -Wno-deprecated -std=c++17 -I include -o MangoD 

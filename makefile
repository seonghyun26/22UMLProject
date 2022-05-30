main: main.cpp build/TestDAO.o build/TestService.o build/AttributesDAO.o build/ProviderDAO.o build/Attribute.o build/Cleaner.o build/GovAgent.o build/Measurement.o build/Provider.o build/Sensor.o build/SimpleUser.o build/User.o build/ServiceCleaners.o build/ServiceGovernement.o build/ServiceGovernement.o build/Login.o build/Interface.o build/ProviderInterface.o
	g++ main.cpp build/*.o -o app

clean:
	rm build/* app

#TESTS
build/TestDAO.o: TESTS/TestDAO.cpp
	g++ -c TESTS/TestDAO.cpp -o build/TestDAO.o
build/TestService.o: TESTS/TestSevice.cpp
	g++ -c TESTS/TestSevice.cpp -o build/TestService.o
#DAO
build/AttributesDAO.o: DAO/AttributesDAO.cpp
	g++ -c DAO/AttributesDAO.cpp -o build/AttributesDAO.o
build/ProviderDAO.o: DAO/ProviderDAO.cpp
	g++ -c DAO/ProviderDAO.cpp -o build/ProviderDAO.o

#data
build/Attribute.o: data/Attribute.cpp
	g++ -c data/Attribute.cpp -o build/Attribute.o

build/Cleaner.o: data/Cleaner.cpp
	g++ -c data/Cleaner.cpp -o build/Cleaner.o

build/GovAgent.o: data/GovAgent.cpp
	g++ -c data/GovAgent.cpp -o build/GovAgent.o

build/Measurement.o: data/Measurement.cpp
	g++ -c data/Measurement.cpp -o build/Measurement.o

build/Provider.o: data/Provider.cpp
	g++ -c data/Provider.cpp -o build/Provider.o

build/Sensor.o: data/Sensor.cpp
	g++ -c data/Sensor.cpp -o build/Sensor.o

build/SimpleUser.o: data/SimpleUser.cpp
	g++ -c data/SimpleUser.cpp -o build/SimpleUser.o

build/User.o: data/User.cpp
	g++ -c data/User.cpp -o build/User.o

#service_book
build/ServiceCleaners.o: sevice_book/ServiceCleaners.cpp
	g++ -c sevice_book/ServiceCleaners.cpp -o build/ServiceCleaners.o

build/ServiceUser.o: sevice_book/ServiceUser.cpp
	g++ -c sevice_book/ServiceUser.cpp -o build/ServiceUser.o

build/ServiceGovernement.o: sevice_book/ServiceGovernement.cpp
	g++ -c sevice_book/ServiceGovernement.cpp -o build/ServiceGovernement.o

#user_interface
build/Login.o: interface/Login.cpp
	g++ -c interface/Login.cpp -o build/Login.o
build/Interface.o: interface/Interface.cpp
	g++ -c interface/Interface.cpp -o build/Interface.o
build/ProviderInterface.o: interface/ProviderInterface.cpp
	g++ -c interface/ProviderInterface.cpp -o build/ProviderInterface.o
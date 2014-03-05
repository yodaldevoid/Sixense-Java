VPATH = dist
CXX = g++
CXXFLAGS = -g -fPIC -c -Wall -I/usr/lib/jvm/java-7-openjdk-amd64/include -I/usr/lib/jvm/java-7-openjdk-amd64/include/linux -I../SixenseSDK_062612/include -I../SixenseSDK_062612/include/sixense_utils -I../SixenseSDK_062612/include/sixense_utils/controller_manager
LDFLAGS = -shared -fPIC -Wl,-rpath,\$$ORIGIN -Wl,-soname,
SOURCES = com_sixense_Sixense.cpp sixense_java_utils.cpp $(addprefix com_sixense_utils_,ButtonStates.cpp ControllerManager.cpp Derivatives.cpp Events.cpp LaserPointer.cpp MousePointer.cpp PlayerMovement.cpp ViewAngles.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: libSixenseJava32.so libSixenseJava64.so

libSixenseJava32.so: $(addprefix build/linux/32/,$(OBJECTS))
	$(CXX) $(LDFLAGS)$@ -m32 -o dist/$@ $^ -L../SixenseSDK_062612/lib/linux/release -lsixense -lsixense_utils

libSixenseJava64.so: $(addprefix build/linux/64/,$(OBJECTS))
	$(CXX) $(LDFLAGS)$@ -m64 -o dist/$@ $^ -L../SixenseSDK_062612/lib/linux_x64/release -lsixense_x64 -lsixense_utils_x64

build/linux/32/%.o: src/native/%.cpp
	$(CXX) $(CXXFLAGS) -m32 -o $@ $<

build/linux/64/%.o: src/native/%.cpp
	$(CXX) $(CXXFLAGS) -m64 -o $@ $<

clean:
	rm -r dist/*.* build/*/*/*.o

CXX = g++
CXXFLAGS = -std=c++17 -Wall -fPIC `pkg-config --cflags Qt5Core Qt5Network`
LDFLAGS = `pkg-config --libs Qt5Core Qt5Network`
SRC = src/main.cpp
TARGET = client

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

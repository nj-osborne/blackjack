# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Targets
TARGET = blackjack
SRC = main.cpp

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe 2>nul || true

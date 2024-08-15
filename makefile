CXX = g++
CXXFLAGS = -Wall -g

TARGET = test.exe

SRCS = sevenseg_solver.test.cpp sevenseg_solver.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
# 定义编译器
CXX=g++

# 定义编译选项
CXXFLAGS=-Wall -std=c++20

# 目标文件列表
OBJS=jsonpp.o demo.o

# 可执行文件名
TARGET=demo

# 默认目标
all: $(TARGET)

# 构建可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 构建对象文件
jsonpp.o: jsonpp.cpp jsonpp.hpp
	$(CXX) $(CXXFLAGS) -c jsonpp.cpp

demo.o: jsonpp.cpp jsonpp.hpp
	$(CXX) $(CXXFLAGS) -c demo.cpp

# 清理编译生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 声明伪目标
.PHONY: all clean

# 定义编译器
CXX := g++
# 定义编译选项
CXXFLAGS := -g -std=c++11
# 定义需要链接的库
LDFLAGS := -lcurl
# 定义源文件和目标文件
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
# 定义可执行文件名
TARGET := a.out

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# 编译源文件为目标文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 编译器
CC = gcc

# 编译选项
CFLAGS = -g -Wall -O2

# 可执行文件
TARGET = test

# 源文件
SRCS = test.c

# 生成目标文件
OBJS = $(SRCS:.c=.o)

# libevent库
LIBEVENT = -levent

# 默认目标
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(LIBEVENT)

# 生成目标文件
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
		rm -f $(TARGET) $(OBJS)

cmake_minimum_required(VERSION 3.22)
project(C_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c)
add_executable(SeqList SeqList.c)
add_executable(LinkList LinkList.c)
add_executable(Stack SeqStack.c)
add_executable(LinkStack LinkStack.c)
add_executable(SeqQueue SeqQueue.c)

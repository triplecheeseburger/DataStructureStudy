cmake_minimum_required(VERSION 3.21)
project(hakim_hchang C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(array
        array/arraylist.c
        array/arraylist.h
        array/main.c
        )

add_executable(linked
        linked/linkedlist.h
        linked/linkedlist.c
        linked/main.c
        )

add_executable(doublyLinkedCircular
        doublyLinkedCircular/doublylist.c
        doublyLinkedCircular/doublylist.h
        doublyLinkedCircular/main.c)

add_executable(poly
        polynomial/polylinkedlist.c
        polynomial/polylinkedlist.h
        polynomial/main.c)
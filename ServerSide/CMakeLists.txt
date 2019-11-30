cmake_minimum_required(VERSION 3.15)
project(ServerSide)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerSide main.cpp ServerManager.cpp ServerManager.h Sender.cpp Sender.h Receiver.cpp Receiver.h Packet.h PacketHandler.cpp PacketHandler.h)
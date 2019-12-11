cmake_minimum_required(VERSION 3.15)
project(ServerSide)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerSide main.cpp  CongestionControl/CongestionControl.cpp CongestionControl/CongestionControl.h ServerManager.cpp ServerManager.h Sender.cpp Sender.h CongestionControl/Slowstart.cpp CongestionControl/Slowstart.h CongestionControl/CongestionHandler.cpp CongestionControl/CongestionHandler.h CongestionControl/State.h RandomLoss.cpp RandomLoss.h GBN.cpp GBN.h Receiver.cpp Receiver.h Packet.h PacketHandler.cpp PacketHandler.h Utilities.cpp Utilities.h)

project(InteractiveShell)
cmake_minimum_required(VERSION 3.1)

set(PATH_RES ${CMAKE_CURRENT_SOURCE_DIR}/ExternalRessources)

include_directories(
	./Core/
	./Firebase/
	./Parser/
	./SqlWrap/
	./Users/
	./EncodePassword/
	./ReadInput/
	./UnconnectedCmd/
	${PATH_RES}/mysql/include/
)

add_executable(interactiveshell
	./main.cpp
	./Core/Core.cpp
	./Users/User.cpp
	./Users/UsersInfos.cpp
	./SqlWrap/SqlWrap.cpp
	./SqlWrap/DatabaseInfos.cpp
	./SqlWrap/RequestBuilder.cpp
	./EncodePassword/EncodePassword.cpp
	./ReadInput/ReadInput.cpp
	./UnconnectedCmd/UnconnectedCmd.cpp
)

target_link_libraries(interactiveshell ${PATH_RES}/mysql/lib/libmysql.lib)
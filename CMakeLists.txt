project(InteractiveShell)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (UNIX)
	set(PATH_RES /usr/local/mysql-8.0.19-macos10.15-x86_64)
endif(UNIX)
if (WIN32)
	set(PATH_RES ${CMAKE_CURRENT_SOURCE_DIR}/ExternalRessources)
endif(WIN32)

include_directories(
	./Core/
	./Parser/
	./SqlWrap/
	./Users/
	./EncodePassword/
	./ReadInput/
	./UnconnectedCmd/
	${PATH_RES}/include/
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

if (UNIX)
	target_link_libraries(interactiveshell ${PATH_RES}/lib/libmysqlclient.dylib)
endif(UNIX)
if (WIN32)
	target_link_libraries(interactiveshell ${PATH_RES}/mysql/lib/libmysql.lib)
endif(WIN32)


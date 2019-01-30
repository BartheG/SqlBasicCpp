project(InteractiveShell)
cmake_minimum_required(VERSION 3.1)

set(PATH_RES ${CMAKE_CURRENT_SOURCE_DIR}/ExternalRessources)

include_directories(
	./Core/
	./Firebase/
	./Parser/
	./SqlWrap/
	${PATH_RES}/mysql/include/
)

add_executable(interactiveshell
	./main.cpp
	./Core/Core.cpp
	./SqlWrap/SqlWrap.cpp
	./SqlWrap/DatabaseInfos.cpp
)

target_link_libraries(interactiveshell ${PATH_RES}/mysql/lib/libmysql.lib)
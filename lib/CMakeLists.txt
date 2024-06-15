file(
	GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_SOURCE_DIR}/include/*.hpp
)

add_library(person SHARED ${SRC_FILES})

target_include_directories(person PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(person PRIVATE cxx_std_17)
target_compile_definitions(person PRIVATE BUILD_DLL_LIBRARY)
file(
	GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(
	hello_dll_class
	${SRC_FILES}
)

target_link_libraries(
	hello_dll_class PRIVATE
	person
)

target_compile_features(hello_dll_class PRIVATE cxx_std_17)
file(
	GLOB_RECURSE IMPL_SRC_FILES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cxx
	${CMAKE_SOURCE_DIR}/include/*.hxx
)

add_library(person_impl SHARED ${IMPL_SRC_FILES})

target_include_directories(person_impl PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(person_impl PRIVATE cxx_std_17)

target_compile_definitions(person_impl PRIVATE BUILD_DLL_LIBRARY)
#=========#=========#=========#=========#=========#=========#=========#=========#=========#=========


file(
	GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_SOURCE_DIR}/include/*.hpp
)

add_library(person STATIC ${SRC_FILES})

target_include_directories(person PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(person PRIVATE cxx_std_17)

target_link_libraries(
	person PRIVATE 
	person_impl
)
#=========#=========#=========#=========#=========#=========#=========#=========#=========#=========
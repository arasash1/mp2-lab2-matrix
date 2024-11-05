set(target ${MP2_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_INCLUDE}/*.h*")

add_library(${target} INTERFACE ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})

#target_include_directories(${target} PUBLIC ${MP2_INCLUDE})
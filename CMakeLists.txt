project(UnitTest)

cmake_minimum_required(VERSION 3.16)
set(TARGET UnitTest)

set(TEST_FILES )
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TEST_FILES)

message("tset files " ${TEST_FILES})
message("src list is " ${SRC_LIST})
foreach(var ${TEST_FILES})
	string(REGEX REPLACE ".*/" "" var ${var})
	string(REGEX REPLACE ".cpp" "" tgt ${var})

	set(TARGET ${tgt}.test)
	add_executable(${TARGET} ${SRC_LIST} ${var} )
	target_link_libraries(${TARGET} ${_MODULE_LINK} ${LUA_LIBRARIES})
	if(WIN32)
		source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/.. FILES ${var})
	endif()
	install(TARGETS ${TARGET} RUNTIME DESTINATION ${EXECUTABLE_OUTPUT_PATH})
endforeach(var)







add_executable( alaio-blocklog main.cpp )

if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

target_include_directories(alaio-blocklog PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries( alaio-blocklog
        PRIVATE appbase
        PRIVATE alaio_chain fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

copy_bin( alaio-blocklog )
install( TARGETS
   alaio-blocklog

   COMPONENT base

   RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
   LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)

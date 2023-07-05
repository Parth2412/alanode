add_executable( alaio-launcher main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

configure_file(config.hpp.in config.hpp ESCAPE_QUOTES)

target_include_directories(alaio-launcher PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(alaio-launcher
                      PRIVATE alaio_chain version fc Boost::program_options ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

install( TARGETS
   alaio-launcher

   RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR} COMPONENT dev EXCLUDE_FROM_ALL
   LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} COMPONENT dev EXCLUDE_FROM_ALL
   ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} COMPONENT dev EXCLUDE_FROM_ALL
)

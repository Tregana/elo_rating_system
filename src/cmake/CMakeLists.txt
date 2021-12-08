set(target elo_rating_system)
add_library(${target} STATIC
  ${PROJECT_SOURCE_DIR}/src/elo_rating_system.cpp
)
install(TARGETS ${target} DESTINATION lib)

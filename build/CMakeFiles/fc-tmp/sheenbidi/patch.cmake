cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for sheenbidi")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/workspaces/C-Sandbox/build/_deps/sheenbidi-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/usr/bin/cmake]====] [====[-DSHEENBIDI_DIR=/workspaces/C-Sandbox/build/_deps/sheenbidi-src]====] [====[-P]====] [====[/workspaces/C-Sandbox/build/_deps/sfml-src/tools/sheenbidi/PatchSheenBidi.cmake]====]
)

endblock()

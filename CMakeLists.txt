# CMakeList.txt: проект CMake для Matrix_extra2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Matrix_extra2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Matrix_extra2 "Matrix_extra2.cpp" "Matrix_extra2.h" "Column.h" "Matrix.cpp" "Matrix.h"   "String.cpp" "String.h" "Column.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Matrix_extra2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

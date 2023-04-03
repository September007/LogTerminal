
set(QT_ROOT "C:/Qt/5.15.2/msvc2019_64")
list(PREPEND CMAKE_PREFIX_PATH "${QT_ROOT}" "${BOOST_ROOT}" )
list(APPEND CMAKE_INCLUDE_PATH "C:/Boost")
list(APPEND CMAKE_LIBRARY_PATH  "C:/Boost/lib")
# override build form
set(BUILD_FORM SHARED)

macro(add_package)
    set(options )
    set(requires PACKAGE URL BRANCH)
    set(multi )

    cmake_parse_arguments(ARG "${options}" "${requires}" "${multi}" ${ARGN})

    include(FetchContent)

    if (NOT ARG_BRANCH)
        set(ARG_BRANCH "master")
    endif()

    FetchContent_Declare(
        ${ARG_PACKAGE}
        GIT_REPOSITORY ${ARG_URL}
        GIT_TAG ${ARG_BRANCH}
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/externals/${ARG_PACKAGE}
    )

    FetchContent_MakeAvailable(${ARG_PACKAGE})
endmacro()

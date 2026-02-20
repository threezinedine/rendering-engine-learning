macro(add_package package_name git_url)
    include(FetchContent)

    FetchContent_Declare(
        ${package_name}
        GIT_REPOSITORY ${git_url}
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/externals/${package_name}
    )

    FetchContent_MakeAvailable(${package_name})
endmacro()

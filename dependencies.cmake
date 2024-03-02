function(clone_repo repo rel_path)
    set (PATH ${PROJECT_SOURCE_DIR}/${rel_path})
    if(NOT IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${rel_path})
    add_custom_command(TARGET CLONE_PROJECTS COMMAND git clone ${repo} ${PATH})
    endif()
endfunction()

clone_repo(git@github.com:lobovAuto/otus_hw6.git homework_6)
clone_repo(git@github.com:google/googletest.git gtest)

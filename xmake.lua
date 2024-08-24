-- Set project name and language
set_project("infinity")
set_languages("c++23")


-- Binary project setup
target("infinity")
    set_targetdir("build/bin")
    set_kind("binary")
    add_files("src/*.cpp")
    add_headerfiles("src/*.h")

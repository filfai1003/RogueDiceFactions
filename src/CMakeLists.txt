set(CMAKE_PREFIX_PATH "C:/SDL")

find_package(SDL3       REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)
find_package(SDL3_ttf   REQUIRED CONFIG)

target_link_libraries(rdf_engine PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)

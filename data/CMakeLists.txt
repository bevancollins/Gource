add_subdirectory(fonts)
add_subdirectory(shaders)

install(
  FILES
    beam.png
    bloom.tga
    bloom_alpha.tga
    file.png
    user.png
  DESTINATION
    data
)

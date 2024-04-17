add_executable(gource
  action.cpp
  action.h
  bloom.cpp
  bloom.h
  caption.cpp
  caption.h
  core/bounds.h
  core/conffile.cpp
  core/conffile.h
  core/display.cpp
  core/display.h
  core/frustum.cpp
  core/frustum.h
  core/fxfont.cpp
  core/fxfont.h
  core/gl.h
  core/logger.cpp
  core/logger.h
  core/mousecursor.cpp
  core/mousecursor.h
  core/pi.h
  core/plane.cpp
  core/plane.h
  core/png_writer.cpp
  core/png_writer.h
  core/ppm.cpp
  core/ppm.h
  core/quadtree.cpp
  core/quadtree.h
  core/regex.cpp
  core/regex.h
  core/resource.cpp
  core/resource.h
  core/sdlapp.cpp
  core/sdlapp.h
  core/seeklog.cpp
  core/seeklog.h
  core/settings.cpp
  core/settings.h
  core/shader.cpp
  core/shader.h
  core/shader_common.cpp
  core/shader_common.h
  core/stringhash.cpp
  core/stringhash.h
  core/texture.cpp
  core/texture.h
  core/tga.cpp
  core/tga.h
  core/timezone.cpp
  core/timezone.h
  core/vbo.cpp
  core/vbo.h
  core/vectors.cpp
  core/vectors.h
  dirnode.cpp
  dirnode.h
  file.cpp
  file.h
  formats/apache.cpp
  formats/apache.h
  formats/bzr.cpp
  formats/bzr.h
  formats/commitlog.cpp
  formats/commitlog.h
  formats/custom.cpp
  formats/custom.h
  formats/cvs-exp.cpp
  formats/cvs-exp.h
  formats/cvs2cl.cpp
  formats/cvs2cl.h
  formats/git.cpp
  formats/git.h
  formats/gitraw.cpp
  formats/gitraw.h
  formats/hg.cpp
  formats/hg.h
  formats/svn.cpp
  formats/svn.h
  gource.cpp
  gource.h
  gource_settings.cpp
  gource_settings.h
  gource_shell.cpp
  gource_shell.h
  key.cpp
  key.h
  logmill.cpp
  logmill.h
  main.cpp
  main.h
  pawn.cpp
  pawn.h
  slider.cpp
  slider.h
  spline.cpp
  spline.h
  textbox.cpp
  textbox.h
  tinyxml/tinystr.cpp
  tinyxml/tinystr.h
  tinyxml/tinyxml.cpp
  tinyxml/tinyxml.h
  tinyxml/tinyxmlerror.cpp
  tinyxml/tinyxmlparser.cpp
  user.cpp
  user.h
  zoomcamera.cpp
  zoomcamera.h
)

if(WIN32)
  target_compile_definitions(gource PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
endif()

find_package(Boost REQUIRED COMPONENTS filesystem system)
find_package(FreeGLUT CONFIG REQUIRED)
find_package(Freetype REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(pcre2 CONFIG REQUIRED)
find_package(PNG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

target_link_libraries(gource PRIVATE
  $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>
  $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
  $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
  $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
  Boost::boost
  Boost::filesystem
  Freetype::Freetype
  GLEW::GLEW
  glm::glm
  GLUT::GLUT
  OpenGL::GL
  PCRE2::8BIT PCRE2::16BIT PCRE2::32BIT PCRE2::POSIX
  PNG::PNG
)

install(
  TARGETS
    gource
  DESTINATION
    .
)

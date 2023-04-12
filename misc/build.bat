@echo off

cls

set subsystem=console

set base_file=app.cpp
set application_name=app
set build_options=
set compile_flags= -nologo -Oi /Z7 /FC /W4 /wd4201 /wd4100 /wd4189 /wd4505 /MT -Gm- -GR- -EHa-
set common_link_flags= -opt:ref
set platform_link_flags=  %common_link_flags% winmm.lib gdi32.lib shell32.lib user32.lib

set CLANGCompileFlags=-g -Wall
set CLANGLinkFlags=

if not exist build mkdir build
pushd build

call cl -Od %build_options% %compile_flags% ../src/%base_file% /link /subsystem:%subsystem% %platform_link_flags% /out:%application_name%.exe

@REM clang %CLANGCompileFlags% %CLANGLinkFlags% ../src/%base_file% -o %application_name%_clang.exe

popd

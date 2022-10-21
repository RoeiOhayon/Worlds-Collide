:: Compile GLFW if isn't compiled
if not exist ..\Worlds-Collide\vendors\glfw\src\Release\glfw3.lib (
    rmdir /S /Q ..\Worlds-Collide\vendors\glfw
    mkdir ..\Worlds-Collide\vendors\glfw
    cmake -S ..\submodules\glfw -B ..\Worlds-Collide\vendors\glfw -D GLFW_USE_WAYLAND=1
    cmake --build ..\Worlds-Collide\vendors\glfw --config Release
)

:: Copy ImGui files
rmdir /S /Q ..\Worlds-Collide\vendors\imgui
mkdir ..\Worlds-Collide\vendors\imgui
for %%e in (h cpp) do (
    xcopy "..\submodules\imgui\*.%%e" ..\Worlds-Collide\vendors\imgui
)
xcopy ..\submodules\imgui\backends\imgui_impl_opengl3_loader.h ..\Worlds-Collide\vendors\imgui\
xcopy ..\submodules\imgui\backends\imgui_impl_opengl3.h ..\Worlds-Collide\vendors\imgui\
xcopy ..\ubmodules\imgui\backends\imgui_impl_opengl3.cpp ..\Worlds-Collide\vendors\imgui\
xcopy ..\submodules\imgui\backends\imgui_impl_glfw.h ..\Worlds-Collide\vendors\imgui\
xcopy ..\submodules\imgui\backends\imgui_impl_glfw.cpp ..\Worlds-Collide\vendors\imgui\
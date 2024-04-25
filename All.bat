cd VeryReal\VeryRealSolucion\dependencies\cMake
call All.bat
cd ..\bin
mkdir .\Assets

cd ..\..
cd ..\bin\ 

xcopy Assets .\..\VeryReal\VeryRealSolucion\bin\Assets /E /Y

cd ..\VeryReal\VeryRealSolucion\
msbuild "VeryRealSolucion.sln" /p:configuration=Debug /p:Platform=x64 /p:PlatformToolset=v143
msbuild "VeryRealSolucion.sln" /p:configuration=Release /p:Platform=x64 /p:PlatformToolset=v143
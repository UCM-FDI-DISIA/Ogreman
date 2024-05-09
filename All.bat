::compilamos el motor
::cd VeryReal\VeryRealSolucion\dependencies\cMake
::call All.bat
cd VeryReal\VeryRealSolucion
::copiamos la carpeta entera de bin a bin de juego
:: que quieres      donde lo quieres 
xcopy bin .\..\..\bin\ /s /e


cd ..\..\
msbuild "OgremanSolucion.sln" /p:configuration=Debug /p:Platform=x64 /p:PlatformToolset=v143
msbuild "OgremanSolucion.sln" /p:configuration=Release /p:Platform=x64 /p:PlatformToolset=v143



cd .\bin

ren  VeryRealProyecto_Release*.exe ________OgreMan_________*.exe
start .




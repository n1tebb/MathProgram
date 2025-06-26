@echo off
chcp 65001 > nul
echo ===============================================
echo   КОМПИЛЯЦИЯ ПРОЕКТА ДЛЯ WINDOWS
echo ===============================================
echo.

echo Проверка наличия компилятора...

REM Попытка компиляции с g++ (MinGW)
where g++ >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo [OK] Найден g++ компилятор
    echo Компилируем проект...
    echo.
    
    g++ -std=c++17 -I. Source.cpp src/Figure.cpp src/Point.cpp src/Real.cpp src/Vector.cpp src/Fraction.cpp src/Integer.cpp -o test_program.exe
    
    if %ERRORLEVEL% EQU 0 (
        echo [УСПЕХ] Компиляция завершена!
        echo Запускаем программу...
        echo.
        echo ===============================================
        test_program.exe
        echo ===============================================
        echo.
        echo Программа завершена.
    ) else (
        echo [ОШИБКА] Ошибка компиляции с g++!
        echo Проверьте, что все файлы на месте.
    )
    goto :end
)

REM Если g++ не найден, пробуем cl (Visual Studio)
where cl >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo [OK] Найден cl компилятор (Visual Studio)
    echo Компилируем проект...
    echo.
    
    cl /EHsc /std:c++17 /I. Source.cpp src/Figure.cpp src/Point.cpp src/Real.cpp src/Vector.cpp src/Fraction.cpp src/Integer.cpp /Fe:test_program.exe >nul 2>nul
    
    if %ERRORLEVEL% EQU 0 (
        echo [УСПЕХ] Компиляция завершена!
        echo Запускаем программу...
        echo.
        echo ===============================================
        test_program.exe
        echo ===============================================
        echo.
        echo Программа завершена.
        del *.obj >nul 2>nul
    ) else (
        echo [ОШИБКА] Ошибка компиляции с cl!
        echo Проверьте, что все файлы на месте.
    )
    goto :end
)

echo [ОШИБКА] Компилятор C++ не найден!
echo.
echo Установите один из компиляторов:
echo - MinGW-w64: https://www.mingw-w64.org/
echo - Visual Studio: https://visualstudio.microsoft.com/
echo - Dev-C++: https://www.bloodshed.net/devcpp.html
echo.

:end
echo.
echo Нажмите любую клавишу для выхода...
pause >nul 
# ping-pong
It is my first game that I made by myself using SDL2 and C++
## Screenshot
Coming soon!
## Compiling instructions
This project uses CMake as its build tool. It also uses the FetchContent module, so no locally installed libraries are needed.
<details>
  <summary>Requirements</summary>
  <br>
  <ol>
    <li>CMake Version 3.2</li>
    <li>C++ Version 20</li>
  </ul>
</details>
    
### Windows
I don't really know how to compile on Windows, so what I'd recommend is generating Visual Studio project files.

First you need to make the build directory

```zsh
mkdir build && cd build
```

Then generate the project files

64 bit:
```zsh
cmake -G "Visual Studio 17 2022" -A x64 ..
```

32 bit:
```zsh
cmake -G "Visual Studio 17 2022" -A Win32 ..
```

If you open your file explorer in this directory, you will find a .sln file. Double click that to open it in Visual Studio and run it from there.

### Unix
After you clone this repository, the first thing you would need to do is make a build folder in the project directory:
    
```zsh
mkdir build && cd build
```

Then build and run the project:

```zsh
cmake .. && cmake --build . && ./ping_pong
```

OPTIONAL: You can build in release mode (faster + optimized)

```zsh
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . --config Release && ./ping_pong  
```

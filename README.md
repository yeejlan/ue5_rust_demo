###UE5 with Rust

UE5 with Rust via Cxx(https://github.com/dtolnay/cxx)

1. create a UE plugin, such as RustPlugin
2. cd RustPlugin and cargo init
3. change crate type to "staticlib"
4. coding src/lib.rs and cargo build --release
5. cargo rustc -q -- --print=native-static-libs to get rust related link libs
6. edit Source/RustPlugin/RustPlugin.Build.cs, add lib and include setting
7. edit Source/Nexus/Nexus.Build.cs to add "RustPlugin"
8. change env.bat to use correct UE5 install location
9. run cargoBuild.bat to compile rust soure, also run build.bat to compile UE5 project
10. run editor.bat, open UE5 Editor, drag "MyActor" to scene and run
11. you can check the message on screen, also in console logs
12. prefer work flow: code, then run cargoBuild.bat to compile rust soure， then in UE5 Editor, use tool|debug|module, search "Nexus" to compile UE5 source code

PS. If you got strange link error, please make sure "cargo" and "Unreal build tool" use the same msvc toolchain which is very importment! 

"cargo" prefer latest msvc toolchain.

"Unreal build tool" chose a verified version, which is NOT latest version most of the time.

# Shrimpet

This is a standalone version of [injectAmsiBypass](https://github.com/boku7/injectAmsiBypass) by Bobby Cooke. Thanks. Same restrictions apply. 

Following [Capt. Meelo's recommendations](https://captmeelo.com/redteam/maldev/2022/02/16/libraries-for-maldev.html), this project uses [skCrypter](https://github.com/skadro-official/skCrypter) and [lazyImporter](https://github.com/JustasMasiulis/lazy_importer). 

## Build 

Due to these fancy libs, a C++ compiler is required.

~~~
x86_64-w64-mingw32-g++ shrimpet.c -o shrimpet.exe
~~~

## Usage

~~~
shrimpet.exe <pid of target>
~~~
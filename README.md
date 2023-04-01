= Uw82c

A simple SDL2 shell to run MicroW8 modules compiled to C using `wasm2c`.

Keys:
* Up/Down/Left/Right Arrow Keys
* Z/X/A/S keys
* R key: restart
* Escape key: quit

== How to compile your own modules

* unpack the uw8 module to a standard WebAssembly module:
  ```
  uw8 unpack my_module.uw8 cart.wasm
  ```
* compile cart.wasm to C:
  ```
  wasm2c cart.wasm -o cart.c
  ```
* profit:
  ```
  make
  ```

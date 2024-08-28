fn main() {

    // This will consider the ffi part in lib.rs in order to
    // generate lib.rs.h and lib.rs.cc
    // minimal example: no C++ code to be called from Rust
    cxx_build::bridge("src/lib.rs")
        .std("c++17")
        .compile("rust_plugin");

    println!("cargo:rerun-if-changed=src/lib.rs");
}



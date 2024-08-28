
#[cxx::bridge(namespace = "rust_plugin")]
mod ffi {

    #[namespace = "rust_plugin::translate"]
    extern "Rust" {
        fn _t(message: String) -> String;
        fn add5(a: i32) -> i32;
    }
}

fn _t(message: String) -> String {
    message.to_uppercase()
}

fn add5(a: i32) -> i32 {
    a + 5
}


use anyhow::Result;

#[cxx::bridge(namespace = "rust_plugin")]
mod ffi {

    #[namespace = "rust_plugin::translate"]
    extern "Rust" {
        fn _t(message: String) -> String;
        fn add5(a: i32) -> i32;
    }

    #[namespace = "rust_plugin::feelout"]
    extern "Rust" {
        fn return_bool(is_true: bool) -> bool;
        fn return_result_ok() -> Result<String>;
        fn return_result_error() -> Result<String>;

        fn a_panicked_function() -> String;
    }
}

fn _t(message: String) -> String {
    message.to_uppercase()
}

fn add5(a: i32) -> i32 {
    a + 5
}

pub fn return_bool(is_true: bool) -> bool {
    if is_true {
        return true;
    }
    false
}

pub fn return_result_ok() -> Result<String> {
    Ok(String::from("a string from ok result"))
}

pub fn return_result_error() -> Result<String> {
    Err(anyhow::anyhow!("bad stuff happened"))
}

pub fn a_panicked_function() -> String {
    panic!("panic for no reason");
}
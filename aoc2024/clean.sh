#!/usr/bin/env bash
# Clean Rust build artifacts
cargo clean

# Remove the generated days_mod.rs
rm -f src/days_mod.rs

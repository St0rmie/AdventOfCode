# Advent of Code 2025

Small collection of Rust solutions for AoC 2025.

## 1) How to run

1. Add your puzzle input to the `inputs/` folder as `dayXX.txt` (e.g., `day01.txt`).
2. From the repository root run:

```bash
cargo run -- <day> <part>
# Example: run day 1 part 2
cargo run -- 1 2
```

## 2) Notes
- `<part>` is `1` or `2`.
- Each run reads `inputs/dayXX.txt` for the given day.
- Run the command from the yearly project root so Cargo and the `inputs/` folder are found.

## 3) Clean directory
```bash
./clean.sh
```

### 4) Create new day template file
```bash
cargo run --bin aoc2025_new <day>
# Example: create day 1 files
cargo run --bin aoc2025_new 1
# This will create days/day01.rs template file
```
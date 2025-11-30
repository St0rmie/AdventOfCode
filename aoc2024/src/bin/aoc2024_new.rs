use std::env;
use std::fs;
use std::path::Path;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        eprintln!("Usage: cargo run --bin aoc_new <day>");
        std::process::exit(1);
    }

    let day: u32 = args[1].parse().expect("Day must be a number");
    let day_file = format!("src/days/day{:02}.rs", day);

    if Path::new(&day_file).exists() {
        eprintln!("File {} already exists", day_file);
        std::process::exit(1);
    }

    let template = format!(
        "pub fn part1(input: &str) -> String {{
    // TODO: implement part 1
    unimplemented!()
}}

pub fn part2(input: &str) -> String {{
    // TODO: implement part 2
    unimplemented!()
}}
"
    );

    fs::write(&day_file, template).expect("Failed to write day file");
    println!("Created {}", day_file);
}

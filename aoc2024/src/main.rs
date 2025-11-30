use std::fs;
mod days_mod;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    
    if args.len() != 3 {
        eprintln!("Usage: aoc2024 <day> <part>");
        std::process::exit(1);
    }

    let day: u32 = args[1].parse().unwrap();
    let part: u32 = args[2].parse().unwrap();

    let input_path = format!("inputs/day{:02}.txt", day);
    let input = fs::read_to_string(input_path).expect("Could not read input");

    if let Some(solver) = days_mod::get_solver(day, part) {
        println!("{}", solver(&input));
    } else {
        eprintln!("No solver for day {day} part {part}");
    }
}

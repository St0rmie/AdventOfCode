use std::fs;
use std::path::Path;

fn main() {
    let days_dir = Path::new("src/days");
    let mut modules = String::new();
    let mut registry = String::new();

    for entry in fs::read_dir(days_dir).unwrap() {
        let file = entry.unwrap().path();

        // consider only rust files
        if file.extension().and_then(|x| x.to_str()) != Some("rs") {
            continue;
        }

        let filename = file.file_stem().unwrap().to_str().unwrap().to_string();

        // expect dayXX
        if let Some(day_num) = filename.strip_prefix("day") {
            // XX must be numbers
            if day_num.parse::<u32>().is_ok() {
                // mod declaration
                modules.push_str(&format!("#[path = \"days/{}.rs\"]\npub mod {};\n", filename, filename));

                registry.push_str(&format!(
                    "    map.insert(({0}, 1), {1}::part1);\n    map.insert(({0}, 2), {1}::part2);\n",
                    day_num.parse::<u32>().unwrap(),
                    filename,
                ));
            }
        }
    }

    let out = format!(
        "use std::collections::HashMap;\n\
         type SolverFn = fn(&str) -> String;\n\
         \n\
         {modules}\n\
         pub fn get_solver(day: u32, part: u32) -> Option<SolverFn> {{\n\
             let mut map: HashMap<(u32,u32), SolverFn> = HashMap::new();\n\
         {registry}\n\
             map.get(&(day, part)).copied()\n\
         }}\n"
    );

    fs::write("src/days_mod.rs", out).unwrap();
}

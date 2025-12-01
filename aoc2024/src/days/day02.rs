pub fn part1(input: &str) -> String {
     // Parse input into vectors
    let parsed_input : Vec<Vec<i32>> = input
        .lines()
        .map(|line| {
            line.split_whitespace()
                .map(|num| num.parse::<i32>().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect();

    // Initialize safe reports count
    let mut safe_rep_count : i32 = 0;


    // Iterate through the reports and find if they're safe
    parsed_input.iter().for_each(|report| if safe(report) {safe_rep_count += 1;});

    return safe_rep_count.to_string()
}

pub fn part2(input: &str) -> String {
         // Parse input into vectors
    let parsed_input : Vec<Vec<i32>> = input
        .lines()
        .map(|line| {
            line.split_whitespace()
                .map(|num| num.parse::<i32>().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect();

    // Initialize safe reports count
    let mut safe_rep_count : i32 = 0;


    // Iterate through the reports and find if they're safe
    parsed_input.iter().for_each(|report| if safe_with_removal(report) {safe_rep_count += 1;});

    return safe_rep_count.to_string()
}

fn safe(report: &Vec<i32>) -> bool {
    // Check for increasing and decreasing order
    let increasing : bool = report.is_sorted_by(|a,b| a <= b);
    let decreasing : bool = report.is_sorted_by(|a,b| a >= b);

    if !(increasing || decreasing){
        return false;
    }

    // Check for differences between 1 and 3
    let mut previous_value : i32 = report[0];
    let mut safe : bool = true;

    report[1..].iter().for_each(|lvl| {
       let difference : i32 = lvl - previous_value;
       if  difference.abs() < 1 || difference.abs() > 3 {
            safe = false;
       }
       previous_value = *lvl;
    });

    return safe;
}

fn safe_with_removal(report: &Vec<i32>) -> bool{
    for i in 0..report.len() {
        let mut report_copy = report.to_vec();
        report_copy.remove(i);
        if safe(&report_copy){
            return true;
        }
    }
    return false;
}
pub fn part1(input: &str) -> String {
    // Parse input into vectors
    let parsed_numbers: Vec<i32> = input
        .lines()
        .map(|line| line[1..].parse::<i32>().unwrap())
        .collect();

    let parsed_rotation : Vec<String> = input
        .lines()
        .map(|line| line.chars().nth(0).unwrap().to_string())
        .collect();
    
    let mut position = 50;
    let mut count_zeros = 0;
    for i in 0..parsed_numbers.len() {
        let shift = &parsed_numbers[i];
        let rotation = &parsed_rotation[i];

        if rotation == "L" {
            position -= shift;
            if position < 0 {
                position = (100 + position) % 100;
            }
        } else {
            position = (position + shift) % 100;
        }

        if position == 0 {
            count_zeros += 1;
        }
    }

    return count_zeros.to_string();
}

pub fn part2(input: &str) -> String {
    // Parse input into vectors
    let parsed_numbers: Vec<i32> = input
        .lines()
        .map(|line| line[1..].parse::<i32>().unwrap())
        .collect();

    let parsed_rotation : Vec<String> = input
        .lines()
        .map(|line| line.chars().nth(0).unwrap().to_string())
        .collect();
    
    let mut position = 50;
    let mut count_zeros = 0;
    for i in 0..parsed_numbers.len() {
        let shift = &parsed_numbers[i];
        let rotation = &parsed_rotation[i];
        let previous_position = position;

        if rotation == "L" {
            position -= shift;
            if position < 0 {
                position = (100 + position) % 100;
            }
        } else {
            position = (position + shift) % 100;
        }

        let position_difference = previous_position - position;
        if position == 0 || position_difference.abs() >= 50 {
            count_zeros += 1;
        }

    }

    return count_zeros.to_string();
}
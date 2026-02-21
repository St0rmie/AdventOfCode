use std::collections::HashMap;

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

    // Separate left and right values
    let mut lefts: Vec<i32> = parsed_input.iter().map(|pair| pair[0]).collect();
    let mut rights: Vec<i32> = parsed_input.iter().map(|pair| pair[1]).collect();

    // Order values within columns
    lefts.sort();
    rights.sort();

    // Calculate distances between paired numbers
    let mut distance_accum : i32 = 0;
    for (l, r) in lefts.iter().zip(rights.iter()) {
        let distance = l-r;
        distance_accum += distance.abs();
    }

    return distance_accum.to_string()
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

    // Separate left and right values
    let lefts: Vec<i32> = parsed_input.iter().map(|pair| pair[0]).collect();
    let rights: Vec<i32> = parsed_input.iter().map(|pair| pair[1]).collect();

    // Create HashMap
    let mut map : HashMap<i32,i32> = HashMap::new();

    // Create entries for the values on the left
    lefts.iter().for_each(|number| {map.insert(*number, 0);});

    // Update the entries with counts of appearances on the right
    rights.iter().for_each(|number| {*map.entry(*number).or_insert(0) += 1;});

    // Generate the final distance
    let mut distance_accum : i32 = 0;
    lefts.iter().for_each(|number| {distance_accum += number * map.get(number).unwrap();});

    return distance_accum.to_string();
}

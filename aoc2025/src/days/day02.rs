pub fn part1(input: &str) -> String {
    // Parse input into vectors of ranges [range_start, range_end]
    let parsed_ranges: Vec<Vec<u64>> = input
        .split(",")
        .map(|range| range.split("-").map(|num| num.parse().unwrap()).collect())
        .collect();

    // Stores the invalid IDs
    let mut invalid_nums : Vec<u64> = Vec::new();

    for range in parsed_ranges.iter(){
        let range_start = range[0];
        let range_end = range[1];

        for i in range_start..=range_end {
            let i_str = i.to_string();
            let i_len = i_str.len();

            if  i_len % 2 != 0 {
                continue
            }

            // Splits number in half
            let (first, last) = i_str.split_at(i_len/2);

            if first == last {
                invalid_nums.push(i);
            }
        }
    }

    //println!("Invalid IDs: {:?}", invalid_nums);
    return invalid_nums.into_iter().reduce(|a,b|  a+b).unwrap().to_string();
}

pub fn part2(_input: &str) -> String {
    // TODO: implement part 2
    unimplemented!();
}

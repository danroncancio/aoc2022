fn main() {
    let mut values : Vec<i32> = include_str!("../../inputs/day1.txt")
        .split("\n\n")
        .map(|x| x.lines().flat_map(str::parse::<i32>).sum())
        .collect();

   values.sort_by(|a, b| b.cmp(a));

    let result: i32 = values.iter().take(3).sum();

    println!("{:?}", result); // 206582
}

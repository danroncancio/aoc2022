fn main() {
    let result: i32 = include_str!("../../inputs/day1.txt")
        .split("\n\n")
        .map(|x| x.lines().flat_map(str::parse::<i32>).sum())
        .max()
        .unwrap();

    println!("{}", result); // 70116
}

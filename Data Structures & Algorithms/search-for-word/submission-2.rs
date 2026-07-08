
impl Solution {
    pub fn exist(mut board: Vec<Vec<char>>, word: String) -> bool
    {
        fn backtrack(
            board: &mut Vec<Vec<char>>,
            x: usize,
            y: usize,
            word: &[char],
            i: usize,
        ) -> bool
        {
            if i >= word.len() {
                return true;
            }
            if x >= board.len() || y >= board[x].len() || board[x][y] != word[i] {
                return false;
            }

            board[x][y] = '\0'; // mark visited in-place

            let found = false
                || backtrack(board, x-1, y, word, i+1)
                || backtrack(board, x+1, y, word, i+1)
                || backtrack(board, x, y-1, word, i+1)
                || backtrack(board, x, y+1, word, i+1)
                ;

            board[x][y] = word[i]; // restore unvisited
            return found;
        }

        let word: Vec<_> = word.chars().collect();

        for x in 0..board.len() { for y in 0..board[x].len() {
            if backtrack(&mut board, x, y, &word, 0) {
                return true;
            }
        }}
        return false;
    }
}

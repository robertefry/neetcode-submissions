
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>)
    {
        let n = matrix.len();

        for i in 0..n { for j in i..n.saturating_sub(i+1)
        {
            let (a,b,c,d) = (i,j,n.saturating_sub(i+1),n.saturating_sub(j+1));

            let tmp = matrix[a][b];
            matrix[a][b] = matrix[d][a];
            matrix[d][a] = matrix[c][d];
            matrix[c][d] = matrix[b][c];
            matrix[b][c] = tmp;
        }}
    }
}

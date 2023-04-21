/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    const cols = new Set(),
          hills = new Set(),
          dales = new Set();
    /**
     * @param {number} row
     * @param {number} col
     * @return {boolean}
     */
    const isSafe = (row, col) => !(cols.has(col) || hills.has(row - col) || dales.has(row + col));
    
    /**
     * @param {number} row
     * @param {number} col
     * @return {void}
     */
    const placeQueen = (row, col) => {
        cols.add(col), hills.add(row - col), dales.add(row + col);
    }
    
    /**
     * @param {number} row
     * @param {number} col
     * @return {void}
     */
    const removeQueen = (row, col) => {
        cols.delete(col), hills.delete(row - col), dales.delete(row + col);
    }
    
    /**
     * @param {number} row
     * @param {number} count
     * @return {number}
     */
    const backtrackQueen = (row, count) => {
        if (row === n) {
            return ++count;
        }
        for (let col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                placeQueen(row, col);
                count = backtrackQueen(row + 1, count);
                removeQueen(row, col);
            }
        }
        return count;
    }
    return backtrackQueen(0, 0);
};

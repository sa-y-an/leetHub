// 1 2 4 5
// 1 3 7 12
func answerQueries(nums []int, queries []int) []int {
    
    sort.Ints(nums);
    n := len(queries)
    m := len(nums)
    
    ans := make([]int, n)
    prefix := make([]int, m) 
    prefix[0] = nums[0]
    
    for i := 1 ; i < m ; i++ {
        prefix[i] = prefix[i-1] + nums[i]
    }
    
    // fmt.Println(prefix)
    
    for i, q := range queries {
        curr := 0
        for j,v := range prefix {
            if( v > q ) {
                break
            }
            curr = j
        }
        if( q < prefix[0] ) {
            ans[i] = 0
        }else {
            ans[i] = curr + 1
        }
    }
    
    return ans
}
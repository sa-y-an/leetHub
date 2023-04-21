func abs(x int) int{
    if x < 0 {
        return -1*x
    }else{
        return x
    }
}

func findErrorNums(nums []int) []int {
    n := len(nums)
    dup := -1
    total := 0
    for _,num := range(nums){
        total += num
    }
    
    for _,num := range(nums){
        idx := abs(num)-1
        if nums[idx] < 0 {
            dup = idx+1
            break
        }
        nums[idx] *= -1
    }
    
    return []int{dup, ((n*(n+1))/2-(total-dup))}
}
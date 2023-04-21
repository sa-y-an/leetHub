func containsNearbyDuplicate(nums []int, k int) bool {
    mpp := map[int][]int{}
    for i,v := range nums {
        mpp[v] = append(mpp[v],i)
    }
    
    for _,arr := range mpp {
        s := arr[0]
        for i := 1 ; i < len(arr) ; i++ {
            if arr[i] - s  <= k {
                return true
            }else {
                s = arr[i]
            }
        }
    }
    
    return false
}
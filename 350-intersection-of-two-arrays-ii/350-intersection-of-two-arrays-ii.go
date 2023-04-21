func min(a,b int) int {
    if a < b {
        return a
    }else{
        return b
    }
}

func intersect(nums1 []int, nums2 []int) []int {
    map1 := map[int]int{}
    map2 := map[int]int{}
    
    
    for _,v := range nums1 {
        map1[v]++
    }
    
    for _,v := range nums2 {
        map2[v]++
    }
    
    ans := []int{}
    for k,v := range map1{
        if cnt,ok := map2[k]; ok {
            times := min(cnt,v)
            for times > 0 {
                ans = append(ans,k)
                times--
            }
        }
    }
    
    return ans
}
func containsNearbyDuplicate(nums []int, k int) bool {
    lastSeen := map[int]int{}
    for i,v := range nums {
        if l,ok := lastSeen[v]; ok && i-l <= k {
            return true
        }
        lastSeen[v] = i
    }
    return false
}
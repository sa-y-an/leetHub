func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type totalTime struct {
    plant, grow int
}

func earliestFullBloom(plantTime []int, growTime []int) int {
    totalTimes := make([]totalTime, len(growTime))
    for i := range totalTimes {
        totalTimes[i] = totalTime{grow: growTime[i], plant: plantTime[i]}
    }
    
    sort.Slice(totalTimes, func(i, j int) bool {
        return totalTimes[i].grow > totalTimes[j].grow
    })

    res, plantDaysQueued := 0, 0
    for i := range growTime {
        res = max(res, plantDaysQueued + totalTimes[i].grow + totalTimes[i].plant)
        plantDaysQueued += totalTimes[i].plant
    }
    
    return res
}

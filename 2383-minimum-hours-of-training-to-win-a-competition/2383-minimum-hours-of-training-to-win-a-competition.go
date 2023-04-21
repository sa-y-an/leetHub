func minNumberOfHours(initialEnergy int, initialExperience int, energy []int, experience []int) int {
    
    totalEnergy := 1
    for _, val := range energy {
        totalEnergy += val
    }
    
    // fmt.Println(totalEnergy)
    
    curr := 0
    maxExp := 0
    for _, val := range experience {
        now := val - curr + 1
        if now > maxExp {
            maxExp = now
        }
        curr += val
    }
    
    // fmt.Println(maxExp)
    
    en := totalEnergy-initialEnergy
    if en < 0 {
        en = 0
    }
    
    exp := maxExp-initialExperience
    if exp < 0 {
        exp = 0
    }
    
    
    // fmt.Println(exp,en)
    return exp + en
    
}
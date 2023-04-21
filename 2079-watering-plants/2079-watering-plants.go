func wateringPlants(plants []int, capacity int) int {
    
    steps := 0
    curr := capacity
    
    for i,_ := range(plants) {
        if( curr >= plants[i] ){
            steps += 1;
            curr -= plants[i];
        }else{
            steps += 2*i + 1;
            curr = capacity-plants[i];
        }
    }
    return steps;
}
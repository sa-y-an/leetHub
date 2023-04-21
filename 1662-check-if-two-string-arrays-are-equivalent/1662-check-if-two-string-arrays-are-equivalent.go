func arrayStringsAreEqual(word1 []string, word2 []string) bool {
    
    var a string;
    var b string;
    
    for _,ch := range(word1) {
        a += ch
    }
    
    for _, ch := range(word2){
        b += ch
    }
    
    
    return a == b
}
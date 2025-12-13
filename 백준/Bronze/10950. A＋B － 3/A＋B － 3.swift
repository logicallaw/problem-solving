import Foundation

var a = readLine()

if let count = a {
    for _ in 0..<Int(count)! {
        let b = readLine()
        
        if let input = b {
            let array = input.components(separatedBy: " ")
            
            print(Int(array[0])! + Int(array[1])!)
        }
    }
}

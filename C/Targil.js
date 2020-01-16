var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let targil = function(num, counter = 0, state = null) {
    let numArray = ("" + num).split("")

    lastNum = numArray[counter - 1]
    currentNum = numArray[counter]


    if (num > 9) {

        if (counter < numArray.length) {

            if (state) {

                if (lastNum < currentNum)
                    targil(num, counter + 1, true)
                else if (lastNum > currentNum)
                    console.log("Answer: 0")
                else if (lastNum === currentNum)
                    targil(num, counter + 1, true)
            } else if (!state && state != null) {
                if (lastNum < currentNum)
                    console.log("Answer: 0")
                else if (lastNum > currentNum)
                    targil(num, counter + 1, false)
                else if (lastNum === currentNum)
                    targil(num, counter + 1, false)
            } else if (counter = 0 || state == null) {
                if (lastNum < currentNum)
                    targil(num, counter + 1, true)
                else if (lastNum > currentNum)
                    targil(num, counter + 1, false)
                else if (lastNum === undefined) {
                    targil(num, counter + 1)
                }
            }
        } else {
            if (state)
                console.log("Answer: 1")
            else
                console.log("Answer: -1")
        }
    } else
        console.log("Sorry! the number must be higher then 9...")
}


let main = function() {
    rl.question("Please enter any number higher then 9: ", function(n) {
        targil(n)
        rl.close();
    });
}

main()

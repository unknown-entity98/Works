const test_cases = ["1 1 1 1","1 2 3 4","1 8 2 8"];
for( let test_case of test_cases){
    const Array = test_case.split(" ");
    if (check_kepler(Array)){
        console.log("Yes");
    }
    else{
        console.log("No");
    }
}

function check_kepler(Arr){
    if (Math.pow(Arr[0],2)/Math.pow(Arr[2],3) == Math.pow(Arr[1],2)/Math.pow(Arr[3],3)){
        return true;
    }
    else{
        return false;
    }
}
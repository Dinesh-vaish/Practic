/*
Qustions @: Sum of digits of a number
1287: 1+2+8+7=18
*/
 function sumOfDigits(num){
    let sum=0;
    while(num>0)
    {
        sum +=nums%10;
        sum =num/10;
    }
    return sum;
 }
 console.log(sumOfDigits(1287))
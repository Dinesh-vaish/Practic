// Qustions 3: find the Number of given Number 
function sumOfDigit(num) 
{
   num=Math.abs(num);
   let cnt=0;
   do {
    cnt++;
    num = Math.floor(num/10);
    
   } while (num > 0);
   return cnt;
}
console.log(sumOfDigit(23456));
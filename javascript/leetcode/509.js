/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    let prev=0, curr=1, next;
    for(let i=2;i<=n;i++)
    {
        if(n<2) return n;
        next=prev+curr;
        prev=curr;
        curr=next;
        
    }
    return curr;
};
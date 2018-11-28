let plus(a:int,b:int)=
    a+b

let rec factorial(x:int)=
    if x<=1 then 1 else x*factorial(x-1)

let comb(n:int, m:int)=
    factorial(n)/(factorial(m)*factorial(n-m))

let a=10
let b=20
let c=plus(a,b)
printfn "a+b=%d" c
let mylist=[(2,1);(4,3);(6,5);(7,6);(3,1)]

let rec work_tuple tuple_list=
    match tuple_list with
        [] -> []
        | (s,i)::tl ->  work_tuple  tl@[comb(s,i)]

let result_list=work_tuple mylist
System.Console.Write(result_list);
System.Console.Read();
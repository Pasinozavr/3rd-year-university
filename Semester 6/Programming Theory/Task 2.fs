//task 1
let rec merge_i l1 l2 =
    match (l1,l2) with
        [],_-> l2
        | _,[] -> l1
        |h1::t1,h2::t2 ->
            if h1 < h2 then h1::(merge_i t1 l2)
            else h2::(merge_i l1 t2)

//task 2
let rec merge ord_fn l1 l2=
    match (l1,l2) with
        [],_ -> l2
        |_,[] -> l1
        |h1::t1,h2::t2 ->
            if ord_fn h1 h2 then h1::(merge ord_fn t1 l2)
            else h2::(merge ord_fn l1 t2)

//task 3
printfn "%A" (merge (<) [11;22;33;44] [10;30;50])
printfn "%A" (merge (>) ["my";"first";"effort"] ["wonderful";"try";"number";"1"])
//task 4
//If at least one of the lists is not in given orderm then the result probably won't be
//task 5
type 'a slist={l: 'a list; ord_fn:'a->'a->bool; is_in_order:bool}
//task6
let insert e ls=
    let rec insert_rec e l=
        match l with
            [] -> [e]
            |h::t -> 
            if ls.ord_fn e h then e::l
            else h::(insert_rec e t)
            in
                if ls.is_in_order then {ls with l=insert_rec e ls.l}
                else {ls with l=e::ls.l}
//task7
let sort ls=
    if ls.is_in_order then ls
    else List.foldBack insert ls.l {l=[]; ord_fn=ls.ord_fn; is_in_order=true}
//task8
let rec merge_ls l1 l2=
    if l1.is_in_order then
        if l2.is_in_order then {l=merge l1.ord_fn l1.l l2.l; ord_fn=l1.ord_fn; is_in_order=true}
        else List.foldBack insert l2.l l1
    else
        if l2.is_in_order then merge_ls l2 l1
        else merge_ls (sort l1) l2

System.Console.Read();
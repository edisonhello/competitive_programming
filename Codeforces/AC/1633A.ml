open Printf
open Scanf


let solve_one = (
)

let remove_last s = (String.sub s 0 ((String.length s) - 1))

let find_div7 s = 
  let rec find_div7_try k =
    if k == 10 then 0
    else if ((s * 10 + k) mod 7) == 0 then (s * 10 + k)
    else find_div7_try (k + 1) in
  find_div7_try 0

let rec solve t =
  if t > 0 then (
    let s = read_line() in
    let v = int_of_string s in
    (
      if v mod 7 == 0 then v
      else find_div7 (int_of_string (remove_last s))
    )
    |> string_of_int
    |> print_endline;
    solve (t - 1)
  )
  else ()

let () = 
  let t = int_of_string (read_line()) in
  solve t

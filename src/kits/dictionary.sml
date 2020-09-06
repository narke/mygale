structure FunctionDict :> DICTIONARY =
struct
  type key = string
  type 'a dict = string -> 'a
  (* The function f represents the mapping in which x is mapped to
   * f(x), except for x such that f raises NotFound, which are not
   * in the mapping.
   *)
  exception NotFound
  fun make () = fn _ => raise NotFound
  fun lookup (d: 'a dict) (key: string) : 'a = d key
  fun insert (d:'a dict) (k:key) (x:'a) : 'a dict =
    fn k' => if k=k' then x else d k'
end

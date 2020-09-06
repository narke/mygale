signature DICTIONARY =
  sig
    (* An 'a dict is a mapping from strings to 'a.
     We write {k1=>v1, k2=>v2, ...} for the dictionary which
     maps k1 to v1, k2 to v2, and so forth. *)

    type key = string
    type 'a dict

    (* make an empty dictionary carrying 'a values *)
    val make : unit -> 'a dict

    (* insert a key and value into the dictionary *)
    val insert : 'a dict -> key -> 'a -> 'a dict

    (* Return the value that a key maps to in the dictionary.
      Raise NotFound if there is not mapping for the key. *)
    val lookup : 'a dict -> key -> 'a
    exception NotFound
end

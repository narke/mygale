signature DOM =
sig
  type node
  val text : string -> node
  val element : node -> string -> string FunctionDict.dict -> node
end

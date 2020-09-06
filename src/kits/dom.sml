structure DOM :> DOM =
struct
  type elementData = {tagName: string, attributes: string FunctionDict.dict}
  datatype nodeType = Text of string | Element of elementData
  datatype node = Children of node list | Type of nodeType | Node of node * nodeType

  fun text data = Type(Text(data))

  fun element children name attributes =
    Node(children, Element({tagName = name, attributes = attributes}))
end

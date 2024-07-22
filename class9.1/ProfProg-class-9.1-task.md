**TASK. MsgPack seriialize**

Use the following link https://github.com/msgpack/msgpack/blob/master/spec.md as a reference for implementation of partial support of serialization for msgpack format.

Write your own implementation that will allow to serialize object of type MyDataType. Such a class should contain one of the value from the list integer, string or std::vector<std::pair<std::string, MyDataType>>. You can suppose that string length is <=30 symbols; integers are always less than 16 bits(e.g. int16_t), map has less than 16 elements.

Implement the methods to store MyDataType instances as a valid msgpack file. You can use convertors from msgpack to json to verify the result file. 

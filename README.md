# Compiling model_b_turn1.cpp

1) protoc --proto_path=. --cpp_out=. person.proto
   Above command generates person.pb.h and person.pb.cc

2) g++ -o model_b_turn1 model_b_turn1.cpp person.pb.cc -lprotobuf



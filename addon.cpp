#include <node.h>
#include <iostream>
#include <string>

using namespace v8;
using namespace std;

void HelloWorld(const FunctionCallbackInfo<Value>& args) {
   Isolate* isolate = args.GetIsolate();
   args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello, world!", NewStringType::kNormal).ToLocalChecked());
}

void AddNumbers(const FunctionCallbackInfo<Value>& args) {
   double a = args[0]->NumberValue();
   double b = args[1]->NumberValue();
   double result = a + b;
   args.GetReturnValue().Set(result);
}

void GetStringLength(const FunctionCallbackInfo<Value>& args) {
   String::Utf8Value val(args[0]->ToString());
   string str (*val);
   int length = str.length();
   args.GetReturnValue().Set(length);
}

void Initialize(Local<Object> exports) {
   NODE_SET_METHOD(exports, "helloWorld", HelloWorld);
   NODE_SET_METHOD(exports, "addNumbers", AddNumbers);
   NODE_SET_METHOD(exports, "getStringLength", GetStringLength);
}

NODE_MODULE(addon, Initialize);

#include <node.h>
#include <stdio.h>

namespace demo
{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Method(const FunctionCallbackInfo<Value>& args)
    {
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello from the C++ world!"));
    }

    void init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "hello", Method);
    }

    NODE_MODULE(addon, init)
}


int multiply(int x, int y);

int main(){ return 0;}

int multiply(int x, int y)
{
    return x * y;
}

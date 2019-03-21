#include <iostream>
#include "myobject.h"

using namespace std;

Napi::FunctionReference MyObject::constructor;

Napi::Object MyObject::Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "MyObject", {
        InstanceMethod("jsToCpp2DArray", &MyObject::JsToCpp2DArray)
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("MyObject", func);
    return exports;
}

MyObject::MyObject(const Napi::CallbackInfo& info) : Napi::ObjectWrap<MyObject>(info)  {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    cout<<"constructor call over"<<endl;
}

Napi::Value MyObject::JsToCpp2DArray(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() <= 0 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "array expected").ThrowAsJavaScriptException();
    }

    Napi::Array array = info[0].As<Napi::Array>();
    uint32_t len = array.Length();
    cout<<"array length="<<len<<endl;
    for(uint32_t i=0;i<len;i++) {
        Napi::Array subArray = static_cast<Napi::Value>(array[i]).As<Napi::Array>();
        uint32_t lenj = subArray.Length();
        for(uint32_t j=0;j<lenj;j++) {
            string element = static_cast<Napi::Value>(subArray[j]).As<Napi::String>().ToString();
                cout<<"i="<<i<<" j="<<j<<" element ="<<element<<endl;
        }
    }
    Napi::Object objOut = Napi::Object::New(env);
    objOut.Set(Napi::String::New(env, "msg"), array);
    return objOut;
}

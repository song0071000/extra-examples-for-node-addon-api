#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <napi.h>

class MyObject : public Napi::ObjectWrap<MyObject> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        MyObject(const Napi::CallbackInfo& info);

    private:
        static Napi::FunctionReference constructor;
        Napi::Value JsToCppObject(const Napi::CallbackInfo& info);
};

#endif

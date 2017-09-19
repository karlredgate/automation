
#include "Thing.h"

using v8::Function;
using v8::FunctionTemplate;
using v8::FunctionCallbackInfo;
using v8::Context;
using v8::Persistent;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;

Persistent<Function> Thing::constructor;

Thing::Thing( double value )
: value(value) {
}

Thing::~Thing() {
}

void
Thing::Init( Local<Object> exports ) {
    Isolate* isolate = exports->GetIsolate();
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(String::NewFromUtf8(isolate, "Thing"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    // Prototype
    NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);
    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "Thing"),
               tpl->GetFunction());
}

void
Thing::New(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if (args.IsConstructCall()) {
        // Invoked as constructor: `new Thing(...)`
        double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
        Thing* obj = new Thing(value);
        obj->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    } else {
        // Invoked as plain function `Thing(...)`, turn into construct call.
        const int argc = 1;
        Local<Value> argv[argc] = { args[0] };
        Local<Context> context = isolate->GetCurrentContext();
        Local<Function> cons = Local<Function>::New(isolate, constructor);
 
 
        Local<Object> result =
           cons->NewInstance(context, argc, argv).ToLocalChecked();
        args.GetReturnValue().Set(result);
    }
}

void
Thing::PlusOne(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Thing* obj = ObjectWrap::Unwrap<Thing>(args.Holder());
    obj->value += 1;
    args.GetReturnValue().Set(Number::New(isolate, obj->value));
}

/* vim: set autoindent expandtab sw=4 : */

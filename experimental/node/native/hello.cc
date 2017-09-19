
#include <stdio.h>
#include <node.h>

#include "Thing.h"

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;

using node::AtExit;

void
Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void
CreateObject(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Object> obj = Object::New(isolate);
    obj->Set(String::NewFromUtf8(isolate, "msg"), args[0]->ToString());
    args.GetReturnValue().Set(obj);
}

void
RunCallback( const FunctionCallbackInfo<Value>& args ) {
    Isolate* isolate = args.GetIsolate();
    Local<Function> cb = Local<Function>::Cast( args[0] );

    const unsigned argc = 1;
    Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "calling a callback") };
    cb->Call( Null(isolate), argc, argv );
}

void
Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Thing* obj1 = node::ObjectWrap::Unwrap<Thing>(
      args[0]->ToObject());
  Thing* obj2 = node::ObjectWrap::Unwrap<Thing>(
      args[1]->ToObject());
  double sum = obj1->val() + obj2->val();
  args.GetReturnValue().Set( Number::New(isolate, sum) );
}

static void
at_exit_cb1( void* arg ) {
  Isolate* isolate = static_cast<Isolate*>(arg);
  HandleScope scope(isolate);
  Local<Object> obj = Object::New(isolate);
  assert(!obj.IsEmpty()); // assert VM is still alive
  assert(obj->IsObject());

  fprintf( stderr, "at exit callback\n" );
}

void init( Local<Object> exports ) {
  NODE_SET_METHOD( exports, "hello", Method );
  NODE_SET_METHOD( exports, "create", CreateObject );
  NODE_SET_METHOD( exports, "cb", RunCallback );
  NODE_SET_METHOD( exports, "add_thing", Add );
  Thing::Init( exports );
  AtExit(at_exit_cb1, exports->GetIsolate());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

/* vim: set autoindent expandtab sw=4 : */

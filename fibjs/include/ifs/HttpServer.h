/***************************************************************************
 *   Copyright (C) 2012 by Leo Hoo                                         *
 *   lion@9465.net                                                         *
 *                                                                         *
 ***************************************************************************/

#ifndef _HttpServer_base_H_
#define _HttpServer_base_H_

/**
 @author Leo Hoo <lion@9465.net>
 */

#include "../object.h"

namespace fibjs
{

class Socket_base;
class Handler_base;
class Stats_base;

class HttpServer_base : public object_base
{
public:
	// HttpServer_base
	static result_t _new(int32_t port, v8::Local<v8::Value> hdlr, obj_ptr<HttpServer_base>& retVal);
	static result_t _new(const char* addr, int32_t port, v8::Local<v8::Value> hdlr, obj_ptr<HttpServer_base>& retVal);
	virtual result_t run(exlib::AsyncEvent* ac) = 0;
	virtual result_t asyncRun() = 0;
	virtual result_t get_socket(obj_ptr<Socket_base>& retVal) = 0;
	virtual result_t get_handler(obj_ptr<Handler_base>& retVal) = 0;
	virtual result_t set_handler(Handler_base* newVal) = 0;
	virtual result_t get_crossDomain(bool& retVal) = 0;
	virtual result_t set_crossDomain(bool newVal) = 0;
	virtual result_t get_forceGZIP(bool& retVal) = 0;
	virtual result_t set_forceGZIP(bool newVal) = 0;
	virtual result_t get_maxHeadersCount(int32_t& retVal) = 0;
	virtual result_t set_maxHeadersCount(int32_t newVal) = 0;
	virtual result_t get_maxUploadSize(int32_t& retVal) = 0;
	virtual result_t set_maxUploadSize(int32_t newVal) = 0;
	virtual result_t get_httpStats(obj_ptr<Stats_base>& retVal) = 0;
	virtual result_t get_tcpStats(obj_ptr<Stats_base>& retVal) = 0;

	DECLARE_CLASSINFO(HttpServer_base);

public:
	static void s__new(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void s_run(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void s_asyncRun(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void s_get_socket(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_get_handler(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_set_handler(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args);
	static void s_get_crossDomain(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_set_crossDomain(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args);
	static void s_get_forceGZIP(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_set_forceGZIP(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args);
	static void s_get_maxHeadersCount(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_set_maxHeadersCount(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args);
	static void s_get_maxUploadSize(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_set_maxUploadSize(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args);
	static void s_get_httpStats(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);
	static void s_get_tcpStats(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args);

public:
	ASYNC_MEMBER0(HttpServer_base, run);
};

}

#include "Socket.h"
#include "Handler.h"
#include "Stats.h"

namespace fibjs
{
	inline ClassInfo& HttpServer_base::class_info()
	{
		static ClassData::ClassMethod s_method[] = 
		{
			{"run", s_run},
			{"asyncRun", s_asyncRun}
		};

		static ClassData::ClassProperty s_property[] = 
		{
			{"socket", s_get_socket, block_set},
			{"handler", s_get_handler, s_set_handler},
			{"crossDomain", s_get_crossDomain, s_set_crossDomain},
			{"forceGZIP", s_get_forceGZIP, s_set_forceGZIP},
			{"maxHeadersCount", s_get_maxHeadersCount, s_set_maxHeadersCount},
			{"maxUploadSize", s_get_maxUploadSize, s_set_maxUploadSize},
			{"httpStats", s_get_httpStats, block_set},
			{"tcpStats", s_get_tcpStats, block_set}
		};

		static ClassData s_cd = 
		{ 
			"HttpServer", s__new, 
			2, s_method, 0, NULL, 8, s_property, NULL, NULL,
			&object_base::class_info()
		};

		static ClassInfo s_ci(s_cd);
		return s_ci;
	}

	inline void HttpServer_base::s_get_socket(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		obj_ptr<Socket_base> vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_socket(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_get_handler(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		obj_ptr<Handler_base> vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_handler(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_set_handler(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args)
	{
		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		PROPERTY_VAL(obj_ptr<Handler_base>);
		hr = pInst->set_handler(v0);

		PROPERTY_SET_LEAVE();
	}

	inline void HttpServer_base::s_get_crossDomain(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		bool vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_crossDomain(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_set_crossDomain(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args)
	{
		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		PROPERTY_VAL(bool);
		hr = pInst->set_crossDomain(v0);

		PROPERTY_SET_LEAVE();
	}

	inline void HttpServer_base::s_get_forceGZIP(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		bool vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_forceGZIP(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_set_forceGZIP(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args)
	{
		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		PROPERTY_VAL(bool);
		hr = pInst->set_forceGZIP(v0);

		PROPERTY_SET_LEAVE();
	}

	inline void HttpServer_base::s_get_maxHeadersCount(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		int32_t vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_maxHeadersCount(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_set_maxHeadersCount(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args)
	{
		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		PROPERTY_VAL(int32_t);
		hr = pInst->set_maxHeadersCount(v0);

		PROPERTY_SET_LEAVE();
	}

	inline void HttpServer_base::s_get_maxUploadSize(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		int32_t vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_maxUploadSize(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_set_maxUploadSize(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void> &args)
	{
		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		PROPERTY_VAL(int32_t);
		hr = pInst->set_maxUploadSize(v0);

		PROPERTY_SET_LEAVE();
	}

	inline void HttpServer_base::s_get_httpStats(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		obj_ptr<Stats_base> vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_httpStats(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s_get_tcpStats(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &args)
	{
		obj_ptr<Stats_base> vr;

		PROPERTY_ENTER();
		PROPERTY_INSTANCE(HttpServer_base);

		hr = pInst->get_tcpStats(vr);

		METHOD_RETURN();
	}

	inline void HttpServer_base::s__new(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		obj_ptr<HttpServer_base> vr;

		CONSTRUCT_ENTER(2, 2);

		ARG(int32_t, 0);
		ARG(v8::Local<v8::Value>, 1);

		hr = _new(v0, v1, vr);

		METHOD_OVER(3, 3);

		ARG(arg_string, 0);
		ARG(int32_t, 1);
		ARG(v8::Local<v8::Value>, 2);

		hr = _new(v0, v1, v2, vr);

		CONSTRUCT_RETURN();
	}

	inline void HttpServer_base::s_run(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		METHOD_INSTANCE(HttpServer_base);
		METHOD_ENTER(0, 0);

		hr = pInst->ac_run();

		METHOD_VOID();
	}

	inline void HttpServer_base::s_asyncRun(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		METHOD_INSTANCE(HttpServer_base);
		METHOD_ENTER(0, 0);

		hr = pInst->asyncRun();

		METHOD_VOID();
	}

}

#endif


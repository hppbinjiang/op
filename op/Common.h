#pragma once
#ifndef __COMMON_H_
#define __COMMON_H_
#include <string>
#include <fstream>
#include <vector>


#define SAFE_CLOSE(h)if(h) CloseHandle(h);h=NULL;

#define SAFE_DELETE(ptr) if(ptr)delete ptr;ptr=nullptr

#define SAFE_DELETE_ARRAY(ptr) if(ptr)delete[] ptr;ptr=nullptr


//#define _sto_wstring(s) boost::locale::conv::to_utf<wchar_t>(s, "GBK")
//#define _wsto_string(s)  boost::locale::conv::from_utf(s,"GBK")

using std::wstring;
using std::string;
using std::vector;

#define DLL_API extern "C" _declspec(dllexport)
//0x0-0xf:normal windows,gdi;0x10-0xf0,dx;0x100-0xf00,opengl;
enum BACKTYPE {
	NORMAL = 0x0000,
	WINDOWS = 0x0001,
	GDI = 0x0002,
	DX = 0x0010,
	DX2 = 0X0020,
	DX3 = 0X0030,
	OPENGL = 0X0100
};

const size_t MAX_IMAGE_WIDTH = 1<<11;
const size_t SHARED_MEMORY_SIZE = 1080 * 1928 * 4;
#ifndef _WIN64
#define SHARED_RES_NAME_FORMAT "op_x86_mutex_%p"
#define MUTEX_NAME_FORMAT "op_x86_shared_res_%p"
#else
#define SHARED_RES_NAME_FORMAT "op_x64_shared_res_%p"
#define MUTEX_NAME_FORMAT "op_x64_mutex_%p"
#endif
//ģ����
extern HINSTANCE gInstance;
//�Ƿ���ʾ������Ϣ
extern int gShowError;

#endif
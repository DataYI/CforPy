// __declspec(dllexport) 的作用是将一个函数声明为导出函数，通常与 extern "C" 合用
#define DllExport __declspec(dllexport)
// 一般C/C++默认的调用方式是 __cdecl, 这种方式需要调用方对函数清栈。如果对外提供API供其它非C++程序使用，调用方无法清栈，会报错。将接口声明为 __stdcall，让API函数自己清栈。
#define WINAPI __stdcall

/* 
C和C++的重命名规则（Name-Mangling）不一样,
C++标准没有规定“Name-Mangling”，不同编译器编译出来的目标文件.obj是不通用的
C标准规定了“Name-Mangling",所以任何一个支持C语言的编译器编译出来的obj文件是通用的。这是一种标准，如用 DLL和使用都采用这种约定，可以解决函数重命名不一致导致的错误。
*/
extern "C" {
    DllExport int WINAPI Add(int x, int y);
    DllExport int WINAPI Del(int x, int y);
    DllExport char * WINAPI Concat(char *s1, char *s2);
}
# import ctypes
from ctypes import windll, c_char_p, create_string_buffer

lib = windll.LoadLibrary('./test.dll')
print(lib.Del(1, 2))
print(lib.Add(1, 2))


def concat(s1, s2):
    '''封装函数，将Python中输入的参数转为c/c++类型，将C++函数返回的结果转为Python类型'''
    lib.Concat.argtypes = [c_char_p, c_char_p]
    lib.Concat.restype = c_char_p
    result = lib.Concat(s1.encode('ascii'), s2.encode('ascii'))
    return result.decode('utf-8')


print(concat('aaa', 'bbb'))
# print('sss'.encode('ascii'))
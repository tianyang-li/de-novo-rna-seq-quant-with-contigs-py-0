from libcpp.string cimport string

def test():
    s = 'abcdefghi'
    cdef string s1 
    s1 = <string><char *> s
    print s1.c_str()


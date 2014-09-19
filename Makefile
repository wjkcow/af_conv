CTAGS = -m64 -Wall -Werror -pthread -O2 -DNDEBUG -DAFCL -lrt -Wl,--no-as-needed
INCLUDEFLAGS =  -I/usr/local/arrayfire/include
LINKFLAGS = -L/usr/local/arrayfire/lib64 -lpthread -lstdc++ -lm -Wl,-rpath,/usr/local/arrayfire/lib64,-rpath,/usr/local/arrayfire/lib64 -lafcl
af_conv: 
	cc $(CTAGS) $(INCLUDEFLAGS) $(LINKFLAGS)  af_conv.cpp -o af_conv

clean:
	rm *.o

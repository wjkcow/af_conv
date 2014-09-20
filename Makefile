CTAGS = -m64 -Wall -Werror -pthread -O2 -DNDEBUG -DAFCL -lrt -Wl,--no-as-needed
INCLUDEFLAGS =  -I/usr/local/arrayfire/include
LINKFLAGS = -L/usr/local/arrayfire/lib64 -lpthread -lstdc++ -lm -Wl,-rpath,/usr/local/arrayfire/lib64,-rpath,/usr/local/arrayfire/lib64 -lafcl
AR = ar
MEX = /usr/local/MATLAB/R2013b/bin/mex



mex:     libaf_conv.a
	${MEX} -L. -laf_conv -v af_conv_valid.cpp LINKFLAGS


libaf_conv.a: af_conv.cpp
	cc $(CTAGS) $(INCLUDEFLAGS) $(LINKFLAGS)  af_conv.cpp -o af_conv.o
	${AR} -r libaf_conv.a af_conv.o



af_conv: af_conv.cpp
	cc $(CTAGS) $(INCLUDEFLAGS) $(LINKFLAGS)  af_conv.cpp -o af_conv

clean:
	rm *.o

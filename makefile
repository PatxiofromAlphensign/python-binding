include=-I/usr/include/python3.5m/
flags=-lpython3.5m
files=py
sharedlib=modd.so 
all: $(sharedlib)

$(sharedlib): $(clean)
	g++ -c -fPIC $(include) $(files).cpp
	g++ -shared  -o $(@) $(files).cpp $(flags) $(include)
clean: 
	rm  *.so || true

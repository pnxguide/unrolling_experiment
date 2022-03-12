no_unroll: sum.cpp
	g++ -o no_unroll.out \
		-ftime-report \
		sum.cpp \
		-O0

unroll_2: sum_unroll_2.cpp
	g++ -o unroll_2.out \
		-ftime-report \
		sum_unroll_2.cpp \
		-O0 \
		-DUNROLL

unroll: sum.cpp
	g++ -o unroll.out \
		-ftime-report \
		sum.cpp \
		-O0 \
		-DUNROLL
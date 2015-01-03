#jingz's file to test gnu compile STL
allTarget:stdafx_target SGI_STL_target
	g++ stdafx.o SGI_STL.o -o SGI_Port_STL.exe
#remove the object files
	rm -rf stdafx.o SGI_STL.o
#complie the cpps into objects
stdafx_target:
	g++ -c stdafx.cpp -o stdafx.o
SGI_STL_target:
	g++ -c SGI_STL.cpp -o SGI_STL.o

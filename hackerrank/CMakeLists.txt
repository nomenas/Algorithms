project(HackerRank)
cmake_minimum_required(VERSION 3.1)

add_definitions(-DFILEINPUT)

set (CMAKE_CXX_STANDARD 11)

add_executable(Piramide formating/piramide.cpp formating/piramide.dat)
add_executable(PrintFloat formating/printingfloat.cpp formating/printingfloat.dat)

add_executable(SherlockAndTheBeast implementation/sherlockandthebeast.cpp implementation/sherlockandthebeast.dat)
add_executable(AngryProfessor implementation/angryprofessor.cpp implementation/angryprofessor.dat)
add_executable(TimeConversion implementation/timeconversion.cpp implementation/timeconversion.dat)
add_executable(LisaWorkbook implementation/lisasworkbook.cpp implementation/lisasworkbook.dat)
add_executable(UtopianTree implementation/utopiantree.cpp implementation/utopiantree.dat)
add_executable(FindDigits implementation/finddigits.cpp implementation/finddigits.dat)
add_executable(SherlockAndSquares implementation/sherlockandsquares.cpp implementation/sherlockandsquares.dat)
add_executable(ServiceLane implementation/servicelane.cpp implementation/servicelane.dat)
add_executable(CutTheSticks implementation/cutthesticks.cpp implementation/cutthesticks.dat)
add_executable(ChocolateFeast implementation/chocolatefeast.cpp implementation/chocolatefeast.dat)
add_executable(TheGridSearch implementation/thegridsearch.cpp implementation/thegridsearch.dat)
add_executable(CavityMap implementation/cavitymap.cpp implementation/cavitymap.dat)
add_executable(CaesarCipher implementation/caesarcipher.cpp implementation/caesarcipher.dat)

add_executable(BinarySearch sorting/binarysearch.cpp sorting/binarysearch.dat)

add_executable(ShortestReach graphs/shortestreach.cpp graphs/shortestreach.dat utils/heap.h)

add_executable(FibornacciModified dynamicprogramming/fibonaccimodified.cpp dynamicprogramming/fibonaccimodified.dat utils/ostream.h utils/xlong.h)
add_executable(TheMaximumSubarray dynamicprogramming/themaximumsubarray.cpp dynamicprogramming/themaximumsubarray.dat)
add_executable(Candies dynamicprogramming/candies.cpp dynamicprogramming/candies.dat)
add_executable(CandiesWithReorder dynamicprogramming/candieswithreorder.cpp dynamicprogramming/candies.dat)

add_executable(2DArrayDS datastructures/arrays/2DArrayDS.cpp datastructures/arrays/2DArrayDS.dat)
add_executable(SparseArrays datastructures/arrays/sparsearrays.cpp datastructures/arrays/sparsearrays.dat)
add_executable(BalancedParentheses datastructures/stacks/balancedarentheses.cpp datastructures/stacks/balancedarentheses.dat)
add_executable(Heap datastructures/heap/heap.cpp)

add_executable(SherlockAndArray search/sherlockandarray.cpp search/sherlockandarray.dat)

----------------------- AUTHORS -----------------------

Sir. Davi Rodrigues de Medeiros

Ms. Iolanda Chagas Costa Paiva


----------------------- COMPILE ------------------------

g++ -Wall -std=c++11 src/*.cpp -I includes -o build/exec

*temporario
g++ -Wall -std=c++11 src/driver_maze.cpp src/canvas.cpp src/maze.cpp -I includes -o exec

---------------------- EXECUTION -----------------------

build/exec < build/entrada.txt > build/saida2.txt

-------------------- PROBLEMS FOUND --------------------
* O parser não consegue tratar o '-' como sinal de um número em alguns casos
* Em alguns casos o programa trata a expressao com uma forma diferente da esperada


----------- ERRORS TREATED BY THE PROGRAM --------------
2 ^8
2 ^(4 * 2)
 2  ^ 4  * 2
 2 + 3 * 40
(2+3) * 40
-2
-3 * -5
5 * -3
10 ^ 2
100 ^ 50
2 +   2 ^ 4
10 - 3 ^3
10 % 2 - 4
4 - 16 % 4
1 % 3
240 / 12
12 / 240
120 / (2- 12 % 10 )
 2 * 4
 10 * 23
 10000 * 50 * 30 * 2 * 5
 30 * 2 * 5
 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9
 1 + 2 + 3 + 4 + 5 + 6 + 7
 1 + 2 - 2 + 3 -3 + 4 - 4 + 5 -5 - 1
 35 - 3 * (-2 + 5) ^2
 54 / 3  ^(12%5) * 2
 ((2-3)*10 - (2^3*5))
    2^3%4*5+32-(540/9)
10000000  - 2
   23 * 4 + 50000000
    (3*4) / (5 * 20000000)
5 ^
5 /
5 *
5  %
5  -
5  +
1 + 2 ^
1 + 2 /
1 + 2 *
1 + 2 %
1 + 2 -
1 + 2 +
2 = 3
2.3 * 4
2 @ 4
2 & 4
4 $
! 1
@ 3
# 4
2 + 3 4
2 - 3 4
2 * 3 4
2 / 3 4
2 % 3 4
( 1 + 2 ) ( 3 * 4 )
1 ( 2 * 300)
(300 + 1 ) - ( 2 )
) 20 - 40
20 ) - 40 
20 + 40 )
( ( 11 % 3 ) * 4 
( 2 * 3 ) + ( 40 % 2
( 2 + ( 4 - ( 5 * ( 6 / ( 7 % 3
( 2 + ( 4 - ( 5 * ( 6 / ( 7 % 3 )
( 2 + ( 4 - ( 5 * ( 6 / ( 7 % 3 ) + 1 )
( 2 + ( 4 - ( 5 * ( 6 / ( 7 % 3 ) + 1 ) + 1 )
( 2 + ( 4 - ( 5 * ( 6 / ( 7 % 3 ) + 1 ) + 1 ) + 1 )
( 2 + ( 4 - ( 5 * ( 6 / ( 7 % 3 ) + 1 ) + 1 ) + 1 ) + 1 )
( ( ( ( 3 * 4 ) * 2 ) * 2 ) * 2 ) / 4
30 / ( 1 - 1 )
10 / ( 3 * 3^-2 )
10 / ( 3 * 0 )
(3 * 0 ) / 2
20 * 20000
30000 / 5 * 500
1 + 2 ^ 64 
1a * 3
      

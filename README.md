# Basic-Console-Base-Resistor-Sum-Calculator
A Basic Console-Based Resistor-sum Calculator
program for calculate circuit overall resistor written in c++

**Source file: Electric/Source1.cpp**

## How to use
Because of limitation of console application, you've to input a circuit part by part.
(Inputting main circuit first, then sub-circuit)
The program will ask for circuit type and either number of sub-circuit or resistor value.
Note that resistor count a circuit
at current state, you've to use single charator (case-insensitive) shorthand value for type of circuit

|  Circuit Type  |Charactor|
|----------------|---------|
|Series Circuit  |    S    |
|Parallel Circuit|    P    |
|Single Resistor |  R or C |

Ex.
```   
   ---------------------
   |                   |                                Input (In order)
   |           |-4Ω----|        (A Series Circuit)    1. s (for series)
Battery----2Ω----3Ω----|        With two sub-circuit  2. 2 (2 sub-circuit)             
                                one is resistor       3. r (first sub-circuit is resistor)
                                other is parallel     4. 2 (that resistor is 2Ω)
                                with two resistor     5. p (second sub-circuit is parallel)
                                                      6. 2 (it's 2 sub-circuit)
                                                      7. r (first sub-circuit in second sub-circuit is resistor)
                                                      8. 3 (that resistor is 3Ω)
                                                      9. r (second sub-circuit in second sub-circuit is resistor)
                                                     10. 4 (that resistor is 3Ω)
                                                     You can actully just input s2r2p2r3r4 in one line and it will (kind of) work [bug]
```

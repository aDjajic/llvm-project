; RUN: cd %S; opt %S/DbgCounter/test.ll -passes=dbgcounter -o %t -output DbgCounter/output.txt
; RUN %t < DbgCounter/input.txt | diff - DbgCounter/expected_output.txt 
; RUN diff DbgCounter/output.txt DbgCounter/expected_console_output.txt
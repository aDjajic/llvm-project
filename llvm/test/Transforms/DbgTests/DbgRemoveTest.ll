; RUN: cd %S; opt %S/DbgRemove/test.ll -passes=dbgremove -o %t
; RUN %t < DbgRemove/input.txt | diff - DbgRemove/expected_output.txt



## PFT

```shell
git clone https://github.com/gavinfielder/pft ; cd pft ; make re ; ./test
```





## FT_PRINTF_TEST

* |- ft_printf/
* |- ft_printf_test

```shell
 git clone https://github.com/cacharle/ft_printf_test.git ;cd ft_printf_test ; make run
```





## 42TESTERS-PRINTF

```shell
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git ; cd 42TESTERS-PRINTF ; bash runtest.sh
```



# printfTester

```c
git clone https://github.com/Tripouille/printfTester.git; cd printfTester; make m
```







# PRINTF_LOVER_V2



```c
git clone https://github.com/charMstr/printf_lover_v2.git;
```







##  테스트 케이스



### 포인터 변수

- 32비트: 16진수 8자리

- - 0x00000000 ~ 0xFFFFFFFF

- 64비트: 16진수 16자리

- - 0x0000000000000000 ~ 0xFFFFFFFFFFFFFFFF

- sizeof로 포인터의 크기를 구해보면 32비트에서는 4바이트, 64비트에서는 8바이트가 나옵니다.

- - **sizeof(포인터)**
  - **sizeof(자료형 \*)**

```c
int num1;
void *ptr = &num1;
printf("%p\n", ptr);    // 008BFB6C: 포인터의 메모리 주소
                        // 0x8bfb6c: 리눅스, OS X에서는 앞에 0x가 붙고, A~F는 소문자로 출력
                        // 높은 자릿수의 0은 생략
```

unsigned long 은 32bit 에서는 4바이트 64bit 에서는 8바이트가 되므로

 

메모리 주소를 담을때 사용가능하다.

### 문자(%c)

* 폭이 있고, `0`이 없고, `-`이 없다면 -> width - 1 만큼 공백 출력, 문자 c 출력

*  `0`이 있고, 마이너스가 없다면 -> width -1 만큼 0출력 , 문자 c 출력

* -가 있으면 -> 왼쪽정렬이므로 c를 출력한 후 width - 1 만큼 공백 출력한다.



### 문자열(%s) + 정밀도

*  정밀도가 더 큰 경우 : 문자열 길이만큼 그대로 출력된다.

```c
printf("%.100s", "pricision")
  >>> precision
```



* 정밀도가 더 작은 경우 : 정밀도 크기 만큼만 출력된다.

```c
printf("%.3s","pricision")
  >>> pre
```





```c
          This bug does not affect the pass/fail result of a test, nor
          the function output--only the reported return value.


Test  11 (nocrash_nullspec_basic) : FAILED.
    (nocrash test: automatically passes provided no unexpected failure)
    First line of code: {return test("%");}
    SEGFAULT

Test  12 (nocrash_nullspec_5w) : FAILED.
    (nocrash test: automatically passes provided no unexpected failure)
    First line of code: {return test("%5");}
    SEGFAULT

Test  13 (nocrash_nullspec_5wzp) : FAILED.
    (nocrash test: automatically passes provided no unexpected failure)
    First line of code: {return test("%05");}
    SEGFAULT

Test  14 (nocrash_nullspec_5wzplj) : FAILED.
    (nocrash test: automatically passes provided no unexpected failure)
    First line of code: {return test("%-05");}
    SEGFAULT

Test  15 (nocrash_nullspec_5wlj) : FAILED.
    (nocrash test: automatically passes provided no unexpected failure)
    First line of code: {return test("%-5");}
    SEGFAULT
```

ft_printf -> ft_printf_c -> ft_type



